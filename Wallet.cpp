#include <vector>
#include <iostream>

#include "Wallet.hpp"
#include "CSVReader.hpp"

Wallet::Wallet()
{
}
/** insert currency to wallet */
void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;

    if (amount < 0)
    {
        throw std::exception{};
    }

    if (currencyMap.count(type) == 0)
    {
        balance = amount;
    }
    else
    {
        balance = amount + currencyMap[type];
    }
    currencyMap[type] = balance;
}
/** check if wallet contains this much currency */
bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencyMap.count(type) > 0 && currencyMap[type] >= amount)
    {
        return true;
    }
    return false;
}

/** insert currency to wallet */
bool Wallet::removeCurrency(std::string type, double amount)
{
    // check if wallet contain currency with amount
    if (containsCurrency(type, amount))
    {
        currencyMap[type] -= amount;
    }
    return false;
}

/** checks if the wallet can cope with this ask/bid */
bool Wallet::canFulfillOrder(OrderBookEntry order)
{
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    double amount = order.amount * order.price;

    if (order.type == OrderBookType::ask)
    {
        std::string currency = currs[0];
        std::cout << "Wallet::canFulfillOrder " << currency << " amount : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    else if (order.type == OrderBookType::bid)
    {
        std::string currency = currs[1];
        std::cout << "Wallet::canFulfillOrder " << currency << " amount : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    return false;
}

/** generate string representation of wallet */
std::string Wallet::toString()
{
    std::string str;

    for (const auto &currency : currencyMap)
    { // first is currency and second is amount
        str += currency.first + " " + std::to_string(currency.second) + "\n";
    }
    return str;
}
/** update the content of the wallet
 * assumes the order was made by owner of the wallet
 */
void Wallet::processSale(const OrderBookEntry &sale)
{
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
    // ask
    if (sale.type == OrderBookType::asksale)
    {
        double outgoinAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];

        currencyMap[incomingCurrency] += incomingAmount;
        currencyMap[outgoingCurrency] -= outgoinAmount;
    }
    else if (sale.type == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0];
        double outgoinAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];

        currencyMap[incomingCurrency] += incomingAmount;
        currencyMap[outgoingCurrency] -= outgoinAmount;
    }
}

/** Print wallet */
void Wallet::printWallet() const
{
    std::cout << std::setw(10) << std::left << "Currency"
              << std::setw(10) << std::left << "Amount" << std::endl;
    for (const auto &[currency, amount] : currencyMap)
    {
        std::cout << std::setw(10) << std::left << currency
                  << std::setw(10) << std::left << amount << std::endl;
    }
}