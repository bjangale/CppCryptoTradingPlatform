
#include <map>
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

        for(const OrderBookEntry& e : orders)
        {
            if(e.timestamp > timestamp)
            {
                next_timeStamp = e.timestamp;
                break;
            }
        }

        if(next_timeStamp == "")
        {
            next_timeStamp = orders[0].timestamp;
        }

        return next_timeStamp;
    }