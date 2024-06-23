#pragma once

#include <string>
#include <map>

#include "OrderBookEntry.hpp"

class Wallet
{
public:
    Wallet();
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);
    /** check if wallet contains this much currency */
    bool containsCurrency(std::string type, double amount);
    /** insert currency to wallet */
    bool removeCurrency(std::string type, double amount);
    /** checks if the wallet can cope with this ask/bid */
    bool canFulfillOrder(OrderBookEntry order);
    /** generate string representation of wallet */
    std::string toString();
    /** update the content of the wallet
     * assumes the order was made by owner of the wallet
     */
    void processSale(const OrderBookEntry& sale);

private:
    std::map<std::string, double> currencyMap;
};