#include <map>

class MerkelMain
{
public:
    void printMenu();
    int getUserInput();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeFrame();
    /*
    Function pointer to store menu in map datastructure
    */
    void initializeMenuMap();
    void processOption(int userOption);

    std::map<int, void (*)()> menuMap;
};