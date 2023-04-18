#include <iostream>

int main () {
    while (true) {
        // 1 print help
        std::cout << "1: Print Help" << std::endl;
        // 2 print exchange stats
        std::cout << "2: Print exchange stats" << std::endl;
        // 3 make an offer
        std::cout << "3: Make an offer" << std::endl;
        // 4 make a bid = buy; offer = sell
        std::cout << "4: Make a bid" << std::endl;
        // 5 print wallet 
        std::cout << "5: Print a wallet" << std::endl;
        // 6 continue
        std::cout << "5: Continue" << std::endl;

        std::cout << "================" << std::endl;
        std::cout << "Type in 1-6" << std::endl;

        int userOption;
        std::cin >> userOption;
        std::cout << "You chose: " << userOption << std::endl;

        if (userOption == 0) 
        {
            std::cout << "Invalid Choice. Choose 1-6" <<std::endl;
        }
        if (userOption == 1) 
        {
            std::cout << "Your aim is to make money, analyze the market" <<std::endl;
        }
            if (userOption == 2) 
        {
            std::cout << "Market looks good" <<std::endl;
        }
        if (userOption == 3) 
        {
            std::cout << "make an offer - enter the amount" <<std::endl;
        }
            if (userOption == 4) 
        {
            std::cout << "make a bid - enter the amount" <<std::endl;
        }
        if (userOption == 5) 
        {
            std::cout << "Your wallet is empty" <<std::endl;
        }
        if (userOption == 6) 
        {
            std::cout << "Going to next time frame" <<std::endl;
        }
    }
    return 0;

}
// to generate a named binary
// g++ listOfOptions.cpp  -o merklerex
// .merkelrex