#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <string>
#include <vector>

#include "CSVReader.hpp"
#include "OrderBookEntry.hpp"

class OrderBook{

public:
/** contruct, reading a csv data file */
OrderBook(const std::string fileName);

/** return vector of all known products in the dataset */
std::vector<std::string> getKnownProducts();

/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product,
                                        std::string timestamp);

/** return price of the highest bid in a sent set */
static double getHighPrice(const std::vector<OrderBookEntry>& orders);

/** return price of the lowest bid in sent set */
static double getLowPrice(const std::vector<OrderBookEntry>& orders);

private:
std::vector<OrderBookEntry> orders;

};

#endif