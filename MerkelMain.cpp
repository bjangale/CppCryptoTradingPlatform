#include <iostream>

#include "MerkelMain.hpp"

void MerkelMain::printMenu()
{
    std::cout << "============================" << std::endl;
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "============================" << std::endl;
}

int MerkelMain::getUserInput()
{
    int userOption;
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the screen instructions." << std::endl;
}

void MerkelMain::printMarketStats()
{
    std::cout << "Display exchange matching engine statistics" << std::endl;
}

void MerkelMain::enterOffer()
{
    std::cout << "Make an offer - enter amount" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make an bid - enter amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}

void MerkelMain::initializeMenuMap(){
 /*   menuMap[1] = MerkelMain::printHelp;
    menuMap[2] = MerkelMain::printMarketStats;
    menuMap[3] = MerkelMain::enterOffer;
    menuMap[4] = MerkelMain::enterBid;
    menuMap[5] = MerkelMain::printWallet;
    menuMap[6] = MerkelMain::gotoNextTimeFrame;
*/
}

void MerkelMain::processOption(int userOption)
{
    if(userOption <=0 || userOption > 6){
        std::cout << "Invalid option choose. Choose 1-6" << std::endl;
        return;
    }

    menuMap[userOption]();

}