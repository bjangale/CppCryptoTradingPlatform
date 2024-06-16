#include <map>
#include <functional>

class MerkelMain
{
public:
    MerkelMain();
    void init();
    void printMenu();
    int getUserInput();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeFrame();
    void processOption(int userOption);

    std::map<int, std::function<void()>> menuMap;
};