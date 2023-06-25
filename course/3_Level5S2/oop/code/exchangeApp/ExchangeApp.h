#pragma once
#ifndef EXCHANGEAPP_H
#define EXCHANGEAPP_H
#include<vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class ExchangeApp
{
    public:
        ExchangeApp();
        void init();
        // state of the app
        OrderBook orders{"bigMidtermFile.csv"};
        std::string currentTime = orders.getEarliestTime();
        Wallet wallet{};

        // public methods that require testing
        void enterAsk();
    private:
        void printMenu();
        int  getUser();
        void printHelp(); 
        void printMarketStats();  
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption); 

};

#endif