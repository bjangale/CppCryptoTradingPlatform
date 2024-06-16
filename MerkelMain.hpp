#pragma once

#include <map>
#include <functional>
#include <vector>

#include "OrderBookEntry.hpp"

class MerkelMain
{
public:
    MerkelMain();
    void init();

private:
    void loadOrderBook();
    void printMenu();
    int  getUserInput();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeFrame();
    void processOption(int userOption);

    std::map<int, std::function<void()>> menuMap;
    std::vector<OrderBookEntry> orders;
};