#include <iostream>

#include "MerkelMain.hpp"
#include "CSVReader.hpp"

MerkelMain::MerkelMain()
{
    menuMap[1] = std::bind(&MerkelMain::printHelp, this);
    menuMap[2] = std::bind(&MerkelMain::printMarketStats, this);
    menuMap[3] = std::bind(&MerkelMain::enterOffer, this);
    menuMap[4] = std::bind(&MerkelMain::enterBid, this);
    menuMap[5] = std::bind(&MerkelMain::printWallet, this);
    menuMap[6] = std::bind(&MerkelMain::gotoNextTimeFrame, this);
}

// To separate concerns – construction creates the object, init makes the object start operating.
void MerkelMain::init()
{
    int userOption;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        std::cout << "Current time is : " << currentTime << std::endl;
        userOption = getUserInput();
        processOption(userOption);
    }
}

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
    for (const std::string &p : orderBook.getKnownProducts())
    {
        std::cout << "Product : " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p,
                                                                  "2020/03/17 17:01:24.884492");
        std::cout << "Ask seen : " << entries.size() << std::endl;
        std::cout << "Max ask : " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask : " << OrderBook::getLowPrice(entries) << std::endl;
    }

    /*print bid spread for all products type*/
    std::cout << "Bid Ask spread : " << std::endl;
    for (const std::string &p : orderBook.getKnownProducts())
    {
        std::cout << "Prouct : " << p << " Bid Ask Spread : "
                  << orderBook.getBidAskSpread(p) << std::endl;
    }

    /** print orderbook depth of bid and ask for all product types */
    std::cout << "OrderBook depth for bid and ask : " << std::endl;
    for (const std::string &p : orderBook.getKnownProducts())
    {
        std::cout << "Product : " << p << " Ask depth : "
                  << orderBook.getOrderBookDepth(p, OrderBookType::ask) << std::endl;
        std::cout << "Product : " << p << " Bid depth : "
                  << orderBook.getOrderBookDepth(p, OrderBookType::bid) << std::endl;
    }
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
    currentTime = orderBook.getNexTime(currentTime);
}

void MerkelMain::processOption(int userOption)
{
    if (userOption <= 0 || userOption > 6)
    {
        std::cout << "Invalid option choose. Choose 1-6" << std::endl;
        return;
    }

    menuMap[userOption]();
}