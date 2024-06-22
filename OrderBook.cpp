
#include <map>
#include <limits>
#include <iostream>
#include <algorithm>

#include "OrderBook.hpp"

/** contruct, reading a csv data file */
OrderBook::OrderBook(const std::string fileName)
{
    orders = CSVReader::readCSV(fileName);
}
/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;

    for (const OrderBookEntry &order : orders)
    {
        prodMap[order.product] = true;
    }

    for (const auto &e : prodMap)
    {
        products.push_back(e.first);
    }
    return products;
}

/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product,
                                                 std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;

    for (const OrderBookEntry &order : orders)
    {
        if (type == order.type &&
            product == order.product &&
            timestamp == order.timestamp)
        {
            orders_sub.push_back(order);
        }
    }
    return orders_sub;
}
/** return price of the highest bid in a sent set */
double OrderBook::getHighPrice(const std::vector<OrderBookEntry> &orders)
{
    double max = INT64_MIN;

    for (auto const &order : orders)
    {
        if (order.price > max)
            max = order.price;
    }
    return max;
}
/** return price of the lowest bid in sent set */
double OrderBook::getLowPrice(const std::vector<OrderBookEntry> &orders)
{
    double min = INT64_MAX;
    for (auto const &order : orders)
    {
        if (order.price < min)
            min = order.price;
    }
    return min;
}

/** return ealiest time in the orderbook*/
std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

/** return the next time after the sent time in the orderbook */
std::string OrderBook::getNexTime(std::string timestamp)
{
    std::string next_timeStamp{""};

    for (const OrderBookEntry &e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timeStamp = e.timestamp;
            break;
        }
    }

    if (next_timeStamp == "")
    {
        next_timeStamp = orders[0].timestamp;
    }

    return next_timeStamp;
}
/** return bid ask spread for given product
 *  bid ask spread is difference between high bid and low ask
 */
double OrderBook::getBidAskSpread(std::string product)
{
    double highBid = std::numeric_limits<double>::min();
    double lowAsk = std::numeric_limits<double>::max();
    for (const OrderBookEntry &e : orders)
    {
        if (e.type == OrderBookType::ask)
        {
            lowAsk = std::min(lowAsk, e.price);
        }
        else if (e.type == OrderBookType::bid)
        {
            highBid = std::max(highBid, e.price);
        }
    }

    if (lowAsk == std::numeric_limits<double>::max() ||
        highBid == std::numeric_limits<double>::min())
    {
        std::cout << "OrderBook::getBidAskSpread - "
                  << "Spread cannot be calculated"
                  << std::endl;
        throw;
    }

    return highBid - lowAsk;
}

/** return order book dept for given product and OrderBookType(bid/ask)
 * this metric measure the market liquidity by aggregating the totle
 * volume(amount) bid and ask at various prices.
 */
double OrderBook::getOrderBookDepth(std::string product, OrderBookType type)
{
    double totalVolume{};
    for (auto const &e : orders)
    {
        if (e.product == product &&
            e.type == type)
        {
            totalVolume += e.amount;
        }
    }
    return totalVolume;
}

/** insert order in ordrebook in ascending timesorted order */
void OrderBook::insertOrder(OrderBookEntry &e)
{
    orders.push_back(e);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimeStamp);
}

/** print all order in orderbook */
void OrderBook::printOrderBook()
{
    for (auto const &e : orders)
    {
        e.printOrderBookEntry();
    }
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(const std::string &product,
                                                       const std::string &timestamp)
{
    // asks = orderbook.asks in this timeframe
    // bids = orderbook.bids in this timeframe
    // sales = []
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    std::vector<OrderBookEntry> sales;

    // sort asks lowest first
    // sort bids highest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    // for ask in asks:
    for (OrderBookEntry &ask : asks)
    {
        // 	for bid in bids:
        for (OrderBookEntry &bid : bids)
        {
            // if bid.price >= ask.price # we have a match
            if (bid.price >= ask.price)
            {
                // sale = new orderbookentry()
                // sale.price = ask.price
                OrderBookEntry sale{ask.price, 0, timestamp, product, OrderBookType::sale};
                // if bid.amount == ask.amount: # bid completely clears ask
                if (bid.amount == ask.amount)
                {
                    //	sale.amount = ask.amount
                    sale.amount = ask.amount;
                    //	sales.append(sale)
                    sales.push_back(sale);
                    //	bid.amount = 0 # make sure the bid is not processed again
                    bid.amount = 0;
                    //	# can do no more with this ask
                    //	# go onto the next ask
                    //	break
                    break;
                }
                // if bid.amount > ask.amount: # ask is completely gone slice the bid
                if (bid.amount > ask.amount)
                {
                    //	sale.amount = ask.amount
                    //	sales.append(sale)
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    //	# we adjust the bid in place
                    //	# so it can be used to process the next ask
                    //	bid.amount = bid.amount - ask.amount
                    bid.amount = bid.amount - sale.amount;
                    //	# ask is completely gone, so go to next ask
                    //	break
                    break;
                }
                // if bid.amount < ask.amount # bid is completely gone, slice the ask
                if (bid.amount > 0 && bid.amount < ask.amount)
                {
                    //	sale.amount = bid.amount
                    //	sales.append(sale)
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    //	# update the ask
                    //	# and allow further bids to process the remaining amount
                    //	ask.amount = ask.amount - bid.amount
                    //	bid.amount = 0 # make sure the bid is not processed again
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    //	# some ask remains so go to the next bid
                    //	continue
                }
            }
        }
    }
    return sales;
}
