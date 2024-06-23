#include <string>
#include <map>

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
    /** generate string representation of wallet */
    std::string toString();

private:
    std::map<std::string, double> currencyMap;
};