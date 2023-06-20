
#include <iostream>
#include <vector>
#include "ExchangeApp.h"
#include "OrderBookEntry.h"
#include "CsvReader.h"
#include "OrderBook.h"


ExchangeApp::ExchangeApp() {}
void ExchangeApp::init() 
{
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 1000);
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
    std::cout << "make an offer - enter the amount: example BTC/ETH,200,5 ie sell 5 BTC for 200 ETH " <<std::endl;
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
        obe.username = "user";
        if (wallet.canFulfillOrder(obe)) 
        {
            orders.insertOrder(obe);
             std::cout << "Order succesfully fullfilled" << std::endl;
        }
        else 
        {
            std::cout << "Insufficient funds" << std::endl;
        }
    } 
    catch(const std::exception& e) 
    {
        std::cout << "ExchangeApp::enterAsk(): Exception on stringsToOBE() function" << std::endl;
    }
}

void ExchangeApp::enterBid() 
{
    std::cout << "make a bid - enter the amount example ETH/BTC,0.5,20 ie buy 0.5 ETH with 0.5*20 BTC" <<std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CsvReader::tokenize(input, ',');
    if (tokens.size() != 3) std::cout << "ExchangeApp::enterBid(): Incorrect number of inputs" << std::endl;
    try 
    {
        OrderBookEntry obe = CsvReader::stringsToOBE(
                        tokens[1], 
                        tokens[2], 
                        currentTime, 
                        tokens[0], 
                        OrderBookType::bid);
        obe.username = "user";    
        if (wallet.canFulfillOrder(obe)) 
        {
            orders.insertOrder(obe);
             std::cout << "Order succesfully fullfilled" << std::endl;
        }
        else 
        {
            std::cout << "Insufficient funds" << std::endl;
        }
    } 
    catch(const std::exception& e) 
    {
        std::cout << "ExchangeApp::enterBid(): Exception on stringsToOBE() function" << std::endl;
    }    
}

void ExchangeApp::printWallet()
{    
    std::cout << "Wallet has BTC ? " << wallet.containsCurrency("BTC", 10) << std::endl;
    std::cout << wallet.toString() << std::endl;
}

void ExchangeApp::gotoNextTimeframe()
{
    std::cout << "Going to next time frame" <<std::endl;
    for (std::string p: orders.getKnownProducts()) 
    {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orders.matchOrders(p, currentTime);
        std::cout << "size of sales " << sales.size() << std::endl;
        for (OrderBookEntry& sale: sales) 
        {
            if (sale.username == "user") 
            {
                wallet.processSale(sale);
            }
            std::cout << "sale amount is " << sale.amount << " and sale price is " << sale.price << std::endl; 
        }

    }
    currentTime = orders.getNextTime(currentTime); 
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

















