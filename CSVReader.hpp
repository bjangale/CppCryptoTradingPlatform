#pragma once

#include <string>
#include <vector>

#include "OrderBookEntry.hpp"

class CSVReader{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(const std::string& fileName);

private:
    static std::vector<std::string> tokenise(const std::string& csvLine);

    static OrderBookEntry stringToOrderBookEntry(const std::vector<std::string>& strings);


};