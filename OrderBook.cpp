#include "OrderBook.hpp"

/** contruct, reading a csv data file */
OrderBook::OrderBook(const std::string fileName)
{

}

/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    return products;
}

/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product,
                                        std::string timestamp)
{
    std::vector<OrderBookEntry> orders;

    return orders;
}

/** return price of the highest bid in a sent set */
double OrderBook::getHighPrice(const std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;

    return max;
}

/** return price of the lowest bid in sent set */
double getLowPrice(const std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;

    return min;
}
