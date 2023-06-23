#include "CandleStick.h"

CandleStick::CandleStick(std::string _timeStamp,
            std::string _product,
            OrderBookType _orderType)
: timeStamp(_timeStamp), 
  product(_product),
  orderType(_orderType)
{
    // // std::vector<OrderBookEntry> orders = CsvReader::readCSV("orderBook.csv");
    // OrderBook orders{"orderBook.csv"};
    // std::cout << "here" << std::endl;
    // high = orders.computeHigh(timeStamp, product, orderType);
}
