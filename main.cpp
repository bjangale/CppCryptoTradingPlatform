#include <iostream>

int main()
{

    while (1)
    {
        std::cout << "1: Print help" << std::endl;
        std::cout << "2: Print exchange stats" << std::endl;
        std::cout << "3: Place an ask" << std::endl;
        std::cout << "4: Place a bid" << std::endl;
        std::cout << "5: Print wallet" << std::endl;
        std::cout << "6: Continue" << std::endl;

        int userOption;
        std::cout << "Type in 1-6" << std::endl;
        std::cin >> userOption;

        switch (userOption)
        {
        case 1:
            std::cout << "Help - choose options from the menu" << std::endl;
            std::cout << "and follow the screen instructions." << std::endl;
            break;
        case 2:
            std::cout << "Display exchange matching engine statistics" << std::endl;
            break;
        case 3:
            std::cout << "Make an offer - enter amount" << std::endl;
            break;
        case 4:
            std::cout << "Make an bid - enter amount" << std::endl;
            break;
        case 5:
            std::cout << "Your wallet is empty." << std::endl;
            break;
        case 6:
            std::cout << "Going to next time frame" << std::endl;
            break;
        default:
            std::cout << "Invalid option choose. Choose 1-6" << std::endl;
        }
    }
    return 0;
}
