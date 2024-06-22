#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <string>
#include <vector>

#include "CSVReader.hpp"
#include "OrderBookEntry.hpp"

class OrderBook
{
public:
    /** contruct, reading a csv data file */
    OrderBook(const std::string fileName);

    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();

    /** return vector of orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product,
                                          std::string timestamp);

    /** return price of the highest bid in a sent set */
    static double getHighPrice(const std::vector<OrderBookEntry> &orders);

    /** return price of the lowest bid in sent set */
    static double getLowPrice(const std::vector<OrderBookEntry> &orders);
    /** return ealiest time in the orderbook*/
    std::string getEarliestTime();
    /** return the next time after the sent time in the orderbook.
     * If there is no next timestamp then wrap around to the start.
     */
    std::string getNexTime(std::string timeStamp);

    /** return bid ask spread for given product
     *  bid ask spread is difference between high bid and low ask
     */
    double getBidAskSpread(std::string product);
    /** return order book dept for given product and OrderBookType(bid/ask)
     * this metric measure the market liquidity by aggregating the totle
     * volume bid and ask at various prices.
     */
    double getOrderBookDepth(std::string product, OrderBookType);
    /** insert order in ordrebook in ascending timesorted order */
    void insertOrder(OrderBookEntry &e);
    /** print all order in orderbook */
    void printOrderBook();

private:
    std::vector<OrderBookEntry> orders;
};

#endif