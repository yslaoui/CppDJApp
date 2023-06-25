#include <iostream>
#include "OrderBookEntry.h"

class CandleStick 
{
    public: 
        CandleStick(std::string _timeStamp,
                    std::string _product,
                    OrderBookType _orderType                    
                    );

        // Arguments to constructor
        std::string timeStamp;
        std::string product;
        OrderBookType orderType;
    
        // Fields to compute
        double open;
        double high;
        double low;
        double close;
};