#include <iostream>

#include "MerkelMain.hpp"

MerkelMain::MerkelMain()
{
    menuMap[1] = std::bind(&MerkelMain::printHelp, this);
    menuMap[2] = std::bind(&MerkelMain::printMarketStats, this);
    menuMap[3] = std::bind(&MerkelMain::enterOffer, this);
    menuMap[4] = std::bind(&MerkelMain::enterBid, this);
    menuMap[5] = std::bind(&MerkelMain::printWallet, this);
    menuMap[6] = std::bind(&MerkelMain::gotoNextTimeFrame, this);

    loadOrderBook();
}
// To separate concerns – construction creates the object, init makes the object start operating.
void MerkelMain::init()
{
    int userOption;
    while (true)
    {
        printMenu();
        userOption = getUserInput();
        processOption(userOption);
    }
}

void MerkelMain::loadOrderBook()
{
    orders.push_back(OrderBookEntry{0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.02187307, 3.467434, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.02187305, 6.85567013, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.021873, 1.345345, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
    orders.push_back(OrderBookEntry{0.02187163, 0.03322569, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});

    orders.push_back(OrderBookEntry{0.02189093, 9.80492203, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02189094, 10.91645003, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02189096, 6.85752424, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02189398, 9.14003499, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
    orders.push_back(OrderBookEntry{0.02189399, 9.14068583, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask});
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
    std::cout << "OrderBook contains " << orders.size() << " entries" << std::endl;
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

void MerkelMain::processOption(int userOption)
{
    if (userOption <= 0 || userOption > 6)
    {
        std::cout << "Invalid option choose. Choose 1-6" << std::endl;
        return;
    }

    menuMap[userOption]();
}