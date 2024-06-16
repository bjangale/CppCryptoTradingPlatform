#include <iostream>
#include <iomanip>

#include "OrderBookEntry.hpp"

/**
 * to_string converts order type to printable string
 */
std::string to_string(OrderBookType type)
{
    switch (type)
    {
    case OrderBookType::bid:
        return "bid";
    case OrderBookType::ask:
        return "ask";
    default:
        return "unknown";
    }
}

OrderBookEntry::OrderBookEntry(double _price, 
                               double _amount,
                               std::string _timestamp, 
                               std::string _product,
                               OrderBookType _type)
                               :price(_price), 
                               amount(_amount), 
                               timestamp(_timestamp),
                               product(_product), 
                               type(_type){
}

void OrderBookEntry::printOrderBookEntry() const{
    std::cout << "Price : " <<std::setw(10)<<std::left<<price 
              <<" Amount : "<<std::setw(9) << amount 
              << " Timestamp : " << timestamp
              << " Product : " << product 
              << " OrderBookType : " << to_string(type) << std::endl;
}