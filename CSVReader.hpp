#pragma once

#include <string>
#include <vector>

#include "OrderBookEntry.hpp"

class CSVReader
{
public:
    CSVReader() = default;
    static std::vector<OrderBookEntry> readCSV(const std::string &fileName);

    static OrderBookEntry stringToOrderBookEntry(const std::string &priceString,
                                                 const std::string &amountString,
                                                 const std::string &timestamp,
                                                 const std::string &product,
                                                 const OrderBookType &type);

    static std::vector<std::string> tokenise(const std::string &csvLine,
                                             const char &separator = ',');

private:
    static OrderBookEntry stringToOrderBookEntry(const std::vector<std::string> &strings);
};