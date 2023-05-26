#pragma once
#ifndef EXCHANGEAPP_H
#define EXCHANGEAPP_H
#include "OrderBookEntry.h"
#include<vector>

class ExchangeApp
{
    public:
        ExchangeApp();
        /** Start the app*/
        void init();

    private:
        std::vector<OrderBookEntry> orders;
        
        void loadOrderBook();
        void printMenu();
        int getUser();
        void printHelp(); 
        void printMarketStats(); 
        void enterOffer(); 
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption); 
};

#endif