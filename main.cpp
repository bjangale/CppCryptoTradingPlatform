#include "MerkelMain.hpp"
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"

int main()
{
    // MerkelMain obj;
    // obj.init();

    std::string csvFileName{"20200317.csv"};

    for (auto v : CSVReader::readCSV(csvFileName))
    {
        v.printOrderBookEntry();
    }

    return 0;
}
