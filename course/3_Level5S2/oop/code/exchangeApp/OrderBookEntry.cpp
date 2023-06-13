#include "OrderBookEntry.h"


OrderBookEntry::OrderBookEntry(double _price,
                       double _amount,
                       std::string _timestamp,
                       std::string _product,
                       OrderBookType _orderType)
                : price(_price), 
                  amount(_amount),
                  timestamp(_timestamp),
                  product(_product),
                  orderType(_orderType)
{
}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string order) 
{
  if (order == "ask") return OrderBookType::ask;
  if (order == "bid") return OrderBookType::bid;
  else return OrderBookType::unknown;

}

bool OrderBookEntry::compareOrders(OrderBookEntry e1, OrderBookEntry e2) 
{
  return (e1.timestamp < e2.timestamp);
}
