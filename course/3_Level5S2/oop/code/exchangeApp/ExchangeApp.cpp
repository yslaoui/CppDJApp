#include <iostream>
#include <vector>
#include "ExchangeApp.h"
#include "OrderBookEntry.h"
#include "CsvReader.h"

ExchangeApp::ExchangeApp() {}
void ExchangeApp::init() 
{
    while (true) 
    {
        loadOrderBook();
        printMenu();
        int input = getUser();
        processUserOption(input);
    }
}

void ExchangeApp::loadOrderBook() 
{
    
    orders = CsvReader::readCSV("orderBook.csv");

}

void ExchangeApp::printMenu() 
{
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
}

int ExchangeApp::getUser() 
{
    std::cout << "================" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;

}

void ExchangeApp::printHelp() 
{
    std::cout << "Your aim is to make money, analyze the market" <<std::endl;
}

void ExchangeApp::printMarketStats() 
{
    std::cout << "Market looks good" <<std::endl;
    int bids = 0;
    int asks = 0;
    for (OrderBookEntry& order: orders) 
    {
        if (order.orderType == OrderBookType::bid) bids++;
        if (order.orderType == OrderBookType::ask) asks++;
    }
    std::cout << "The order book is made of " << bids << " bids and " << asks << " asks." << std::endl;
}

void ExchangeApp::enterOffer() 
{
    std::cout << "make an offer - enter the amount" <<std::endl;
}

void ExchangeApp::enterBid() 
{
    std::cout << "make a bid - enter the amount" <<std::endl;
}

void ExchangeApp::printWallet()
{
    std::cout << "Your wallet is empty" <<std::endl;
}

void ExchangeApp::gotoNextTimeframe()
{
    std::cout << "Going to next time frame" <<std::endl;
}


void ExchangeApp::processUserOption(int userOption) 
{
    if (userOption == 0) 
    {
        std::cout << "Invalid Choice. Choose 1-6" <<std::endl;
    }
    if (userOption == 1) 
    {
        printHelp();
    }
    if (userOption == 2) 
    {
        printMarketStats();
    }
    if (userOption == 3) 
    {
        enterOffer();
    }
        if (userOption == 4) 
    {
        enterBid() ;
    }
    if (userOption == 5) 
    {
        printWallet();
    }
    if (userOption == 6) 
    {
        gotoNextTimeframe();
    }
}
