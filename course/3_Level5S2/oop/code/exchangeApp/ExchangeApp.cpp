#include <iostream>
#include <vector>
#include "ExchangeApp.h"
#include "OrderBookEntry.h"
#include "CsvReader.h"
#include "OrderBook.h"

ExchangeApp::ExchangeApp() {}
void ExchangeApp::init() 
{
    while (true) 
    {
        printMenu();
        int input = getUser();
        processUserOption(input); 
    }
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
    std::cout << "6: Continue" << std::endl;
    // Print current time
    std::cout << "The current time is " << currentTime << std::endl;
}

int ExchangeApp::getUser() 
{
    std::cout << "================" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
    int userOption;
    std::string line;
    std::getline(std::cin, line);
    try 
    {
        userOption = std::stoi(line);
    }
    catch(const std::exception&) 
    {
        //
    }
    
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;

}

void ExchangeApp::printHelp() 
{
    std::cout << "Your aim is to make money, analyze the market" <<std::endl;
}

void ExchangeApp::printMarketStats() 
{
    std::cout << "The products in the market are " << std::endl;
    for (const std::string& prod : orders.getKnownProducts()) 
    {
        std::vector<OrderBookEntry> orders_sub;   
        orders_sub = orders.getOrders(OrderBookType::ask, 
                                      prod, 
                                      currentTime);
        std::cout << "Product: " << prod << " " << std::endl;
        std::cout << "Asks seen " << orders_sub.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHigherPrice(orders_sub) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowerPrice(orders_sub) << std::endl;

    }

}

void ExchangeApp::enterAsk() 
{
    std::cout << "make an offer - enter the amount: example ETH/BTC,200,5 " <<std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CsvReader::tokenize(input, ',');
    if (tokens.size() != 3) std::cout << "ExchangeApp::enterAsk(): Incorrect number of inputs" << std::endl;
    try 
    {
        OrderBookEntry obe = CsvReader::stringsToOBE(
                        tokens[1], 
                        tokens[2], 
                        currentTime, 
                        tokens[0], 
                        OrderBookType::ask);    
        orders.insertOrder(obe);
    } 
    catch(const std::exception& e) 
    {
        std::cout << "ExchangeApp::enterAsk(): Exception on stringsToOBE() function" << std::endl;
    }

    
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
    currentTime = orders.getNextTime(currentTime); 
    std::vector<OrderBookEntry> sales = orders.matchOrders("DOGE/BTC", currentTime);
    for (OrderBookEntry& sale: sales) 
    {
        std::cout << "sale amount is " << sale.amount << " and sale price is " << sale.price << std::endl; 
    }
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
        enterAsk();
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
