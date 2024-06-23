
#include "Wallet.hpp"

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