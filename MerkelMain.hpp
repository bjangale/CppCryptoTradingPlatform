#pragma once

#include <map>
#include <functional>
#include <vector>

#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"

class MerkelMain
{
public:
    MerkelMain();
    void init();

private:
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
    OrderBook orderBook{"20200317.csv"};
    std::string currentTime; 
};