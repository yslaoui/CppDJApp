#pragma once
#ifndef EXCHANGEAPP_H
#define EXCHANGEAPP_H
#include<vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class ExchangeApp
{
    public:
        ExchangeApp();
        /** Start the app*/
        void init();
        void enterAsk(); 

        OrderBook orders{"orderBook.csv"};
        std::string currentTime = orders.getEarliestTime();

    private:
        void printMenu();
        int getUser();
        void printHelp(); 
        void printMarketStats(); 
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption); 

};

#endif