#pragma once
#include <iostream>
#include <map>
#include "OrderBookEntry.h"

class Wallet 
{
    public: 
        Wallet();
        /** In wallet insert amount of curency*/
        void insertCurrency(std::string currency, double amount);
        /** In wallet reduce currency holding by amount*/
        bool removeCurrency(std::string currency, double amount);
        /** Check if the wallet contains at least amout of currency*/
        bool containsCurrency(std::string currency, double amount);
        /** Check if the wallet contains enough currency to fulfill the order*/
        bool canFulfillOrder(OrderBookEntry order);
        /**print the content of the wallet*/
        std::string toString();
        /** updates wallet with payoff after sale */
        void processSale(OrderBookEntry& sale);
        
    private: 
        std::map<std::string, double> wallet;
};