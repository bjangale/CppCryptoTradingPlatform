#include <iostream>

#include "MerkelMain.hpp"
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include "Wallet.hpp"
#include "WalletManager.hpp"

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

/** WalletManager test */
/*
    WalletManager wallMgr;

    wallMgr.addWallet("Bhushan");
    wallMgr.addWallet("Bhumi");

    wallMgr.gerUserWallet("Bhushan").insertCurrency("BTC", 30.235);
    wallMgr.gerUserWallet("Bhushan").insertCurrency("USD", 35.235);

    wallMgr.gerUserWallet("Bhumi").insertCurrency("DOGE", 21.843);
    wallMgr.gerUserWallet("Bhumi").insertCurrency("ETH", 45.355);

    wallMgr.printWallets();
  */
    return 0;
}
