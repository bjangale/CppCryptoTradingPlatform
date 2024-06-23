#include <iostream>

#include "MerkelMain.hpp"
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include "Wallet.hpp"

int main()
{
    MerkelMain obj;
    obj.init();
    /*
        Wallet wallet;

        std::cout<<"Insert 10 BTC and 10000 USDT in wallet"<<std::endl;
        wallet.insertCurrency("BTC", 10);
        wallet.insertCurrency("USDT", 10000);
        std::cout << "Print wallet : " << std::endl
                  << wallet.toString() << std::endl;
        std::cout << "Wallet Contains Bitcoin : " << std::boolalpha
                  << wallet.containsCurrency("BTC", 10) << std::endl;
        wallet.removeCurrency("USDT", 1000);
        std::cout << "Print wallet after removing 1000 USDT: " << std::endl
                  << wallet.toString() << std::endl;
    */

    return 0;
}
