#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown,
    bidsale,
    asksale
};

class OrderBookEntry
{
public:
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType type;
    std::string userName;
    /**
     *OrderBookEntry contstructor take 5 arguments
     */
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _type,
                   std::string _userName = "dataset");
    /**
     *Print all OrderBookEntry parameters.
     */
    void printOrderBookEntry() const;

    static OrderBookType stringToOrderBookType(std::string s);
    static std::string orderBookTypeToString(OrderBookType type);

    static bool compareByTimeStamp(const OrderBookEntry &e1,
                                   const OrderBookEntry &e2)
    {
        return e1.timestamp < e2.timestamp;
    }

    static bool compareByPriceAsc(const OrderBookEntry &e1, const OrderBookEntry &e2)
    {
        return e1.price < e2.price;
    }

    static bool compareByPriceDesc(const OrderBookEntry &e1, const OrderBookEntry &e2)
    {
        return e1.price > e2.price;
    }
};
