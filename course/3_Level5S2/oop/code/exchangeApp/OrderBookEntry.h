#pragma once
#ifndef ORDERBOOKENTRY_H
#define ORDERBOOKENTRY_H
#include <string>


enum class OrderBookType{bid, ask, unknown, sale};

#pragma once

class OrderBookEntry
{
    public:
        OrderBookEntry(double _price,
                    double _amount,
                    std::string _timestamp,
                    std::string _product,
                    OrderBookType _orderType);
                    
        static OrderBookType stringToOrderBookType(std::string order);
        
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;

    /** comparing helper for sorting function */
    static bool compareOrders(OrderBookEntry e1, OrderBookEntry e2);
        
};

#endif