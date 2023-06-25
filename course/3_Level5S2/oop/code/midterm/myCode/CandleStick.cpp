#include "CandleStick.h"

CandleStick::CandleStick(std::string _timeStamp,
            std::string _product,
            OrderBookType _orderType)
: timeStamp(_timeStamp), 
  product(_product),
  orderType(_orderType)
{
    
}