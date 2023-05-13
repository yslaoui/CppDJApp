#ifndef ORDERBOOKENTRY_H
#define ORDERBOOKENTRY_H
#include <string>

enum class OrderBookType{bid, ask};

#pragma once

class OrderBookEntry
{
    public:
        OrderBookEntry(double _price,
                    double _amount,
                    std::string _timestamp,
                    std::string _product,
                    OrderBookType _orderType);
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};

#endif