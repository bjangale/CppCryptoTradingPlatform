#include <iostream>
#include <iomanip>

#include "OrderBookEntry.hpp"

OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               std::string _timestamp,
                               std::string _product,
                               OrderBookType _type,
                               std::string _userName)
    : price(_price),
      amount(_amount),
      timestamp(_timestamp),
      product(_product),
      type(_type),
      userName(_userName)
{
}

void OrderBookEntry::printOrderBookEntry() const
{
    std::cout << "Price : " << std::setw(10) << std::left << price
              << " Amount : " << std::setw(9) << amount
              << " Timestamp : " << timestamp
              << " Product : " << product
              << " OrderBookType : " << orderBookTypeToString(type)
              << " UserName : " << userName << std::endl;
}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if (s == "ask")
        return OrderBookType::ask;
    if (s == "bid")
        return OrderBookType::bid;
    if (s == "bidsale")
        return OrderBookType::bidsale;
    if (s == "asksale")
        return OrderBookType::asksale;

    return OrderBookType::unknown;
}

/**
 * to_string converts order type to printable string
 */
std::string OrderBookEntry::orderBookTypeToString(OrderBookType type)
{
    switch (type)
    {
    case OrderBookType::bid:
        return "bid";
    case OrderBookType::ask:
        return "ask";
    case OrderBookType::bidsale:
        return "bidsale";
    case OrderBookType::asksale:
        return "asksale";
    default:
        return "unknown";
    }
}