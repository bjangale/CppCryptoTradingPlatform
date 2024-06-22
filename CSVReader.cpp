
#include <fstream>
#include <iostream>

#include "CSVReader.hpp"

std::vector<OrderBookEntry> CSVReader::readCSV(const std::string &fileName)
{
    std::vector<OrderBookEntry> entries;

    std::ifstream csvFile{fileName};

    if (csvFile.is_open())
    {
        std::string csvLine;

        while (getline(csvFile, csvLine))
        {
            std::vector<std::string> tokens = CSVReader::tokenise(csvLine);
            try
            {
                entries.push_back(stringToOrderBookEntry(tokens));
            }
            catch (...)
            {
                continue;
            }
        }
    }
    else
    {
        std::cout << "Failed of open file : " << fileName << std::endl;
    }

    return entries;
}

std::vector<std::string> CSVReader::tokenise(const std::string &csvLine,const char& separator)
{
    std::vector<std::string> tokens;

    std::string::size_type start = csvLine.find_first_not_of(separator);
    std::string::size_type end{};
    std::string token;
    if (start == std::string::npos)
        return tokens;
    do
    {
        end = csvLine.find_first_of(separator, start);

        if (end == std::string::npos)
            token = csvLine.substr(start, csvLine.length() - start);
        else
            token = csvLine.substr(start, end - start);

        start = end + 1;
        tokens.push_back(token);

    } while (end != std::string::npos);

    return tokens;
}

OrderBookEntry CSVReader::stringToOrderBookEntry(const std::vector<std::string> &tokens)
{
    double price, amount;

    if (tokens.size() != 5)
    {
        std::cout << "Bad line !" << std::endl;
        throw std::exception{};
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
        // std::cout << "Price : " << price << " Amount : " << amount << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Bad double!" << std::endl;
        throw;
    }

    OrderBookEntry entry{price, amount, tokens[0], tokens[1],
                         OrderBookEntry::stringToOrderBookType(tokens[2])};

    return entry;
}

OrderBookEntry CSVReader::stringToOrderBookEntry(const std::string &priceString,
                                                 const std::string &amountString,
                                                 const std::string &timestamp,
                                                 const std::string &product,
                                                 const OrderBookType &type)
{
    double price, amount;

    try
    {
        price = std::stod(priceString);
        amount = std::stod(amountString);
        // std::cout << "Price : " << price << " Amount : " << amount << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << __FUNCTION__ << " Bad double!" << std::endl;
        throw;
    }

    OrderBookEntry entry{price, amount, timestamp, product, type};

    return entry;
}