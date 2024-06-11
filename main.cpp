#include <iostream>

void printMenu()
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

int getUserInput()
{
    int userOption;
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    return userOption;
}

void printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the screen instructions." << std::endl;
}

void printMarketStats()
{
    std::cout << "Display exchange matching engine statistics" << std::endl;
}

void enterOffer()
{
    std::cout << "Make an offer - enter amount" << std::endl;
}

void enterBid()
{
    std::cout << "Make an bid - enter amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

void gotoNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}

void processOption(int userOption)
{
    switch (userOption)
    {
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterOffer();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        gotoNextTimeFrame();
        break;
    default:
        std::cout << "Invalid option choose. Choose 1-6" << std::endl;
    }
}

int main()
{

    while (1)
    {
        printMenu();
        int userOption = getUserInput();
        processOption(userOption);
    }

    return 0;
}
