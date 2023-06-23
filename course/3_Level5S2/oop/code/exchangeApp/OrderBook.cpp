#include "OrderBook.h"
#include "CsvReader.h"
#include <map>
#include <algorithm> // for std::sort
#include "ExchangeApp.h"
/*
First create the cpp file for the class implement a dummy version of the three
methods and make it compile  In the constructor use the readCsv method and store
the result in the orders attribute  Then compile
*/
 

OrderBook::OrderBook(std::string filename)
   {
      orders = CsvReader::readCSV(filename);
   }

std::vector<std::string> OrderBook::getKnownProducts()
   {    
       std::vector<std::string> products;
       std::map<std::string, bool> prodMap;
       for (OrderBookEntry& order: orders) 
       {
         prodMap[order.product] = true;
       }
       for (const auto& e: prodMap) 
       {
         products.push_back(e.first);
       }
       return products;               
   }
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                std::string product,
                                                std::string timeStamp)
   {
       std::vector<OrderBookEntry> orders_sub;
       for (const auto& order: orders) 
       {
         if (order.orderType == type && 
             order.product == product && 
             order.timestamp == timeStamp) 
            {
               orders_sub.push_back(order);
            }       
       }
       return orders_sub;               
   }


double OrderBook::getHigherPrice(std::vector<OrderBookEntry> orders_sub) 
{
   double max =  orders_sub[0].price;

   for (OrderBookEntry& e: orders_sub) 
   {
      if (e.price > max) 
      {
        max = e.price; 
      }  
   }
   return max;
}

double OrderBook::getLowerPrice(std::vector<OrderBookEntry> orders_sub) 
{
   double min =  orders_sub[0].price;

   for (OrderBookEntry& e: orders_sub) 
   {
      if (e.price < min) 
      {
        min = e.price; 
      }  
   }
   return min;
}

std::string OrderBook::getEarliestTime() 
{
   return orders[0].timestamp;
}  

std::string OrderBook::getNextTime(std::string timeStamp) 
{
   std::string nextTimeStamp;
   std::string result;
   for (OrderBookEntry& e: orders) 
   {
      if (e.timestamp > timeStamp) 
      {
         nextTimeStamp = e.timestamp;
         break;
      }
   }

   nextTimeStamp == "" ? result = orders[0].timestamp :  result = nextTimeStamp;
   return result;
}


void OrderBook::insertOrder(OrderBookEntry& order) 
{
   orders.push_back(order);
   std::sort(orders.begin(), orders.end(), OrderBookEntry::compareOrders);
   
}


std::vector<OrderBookEntry> OrderBook::matchOrders(std::string product, std::string timeStamp) 
{
   std::vector<OrderBookEntry> sales;
   std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timeStamp);
   std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timeStamp);
   // Next sort the orders
   std::sort(asks.begin(), asks.end(), OrderBookEntry::comparePriceAsc);
   std::sort(bids.begin(), bids.end(), OrderBookEntry::comparePriceDesc);
   for (OrderBookEntry& ask: asks) 
   {
      for (OrderBookEntry& bid: bids) 
      {
         if (bid.price >= ask.price) 
         {
            OrderBookEntry sale{ask.price, 0, timeStamp, product, OrderBookType::sale};
            if (ask.username == "user") 
            {
               sale.username = "user";
               sale.orderType = OrderBookType::asksale; 

            }
            if (bid.username == "user") 
            {
               sale.username = "user";
               sale.orderType = OrderBookType::bidsale; 

            }
            if (bid.amount == ask.amount) 
            {
               sale.amount = ask.amount;
               bid.amount = 0;
               sales.push_back(sale);
               break;
            }         
            if (bid.amount > ask.amount) 
            {
               sale.amount = ask.amount;
               bid.amount = bid.amount - ask.amount;
               sales.push_back(sale);
               break;            
            }
            if (bid.amount < ask.amount && bid.amount > 0)
            {
               sale.amount = bid.amount;
               bid.amount = 0;
               ask.amount = ask.amount - bid.amount;
               sales.push_back(sale);
               continue;
            }
         }

      }
   }
   return sales;
}       



 std::vector<OrderBookEntry> OrderBook::getterOrders() 
 {
   return orders;
 }

std::string OrderBook::getPreviousTime(std::string timeStamp) 
{
   std::string previousTimeStamp;
   std::string result;
   std::vector<OrderBookEntry>::reverse_iterator it;
   for (it = orders.rbegin(); it != orders.rend(); it++) 
   {
      if (it->timestamp < timeStamp) 
      {
         previousTimeStamp = it->timestamp;
         break;
      }
   }

   previousTimeStamp == "" ? result = orders[0].timestamp :  result = previousTimeStamp;
   return result;
}


 double OrderBook::averagePrice(std::vector<OrderBookEntry> orderEntry) 
 {
   double sumValue = 0;
   double sumPrice = 0;

   for (OrderBookEntry& o: orderEntry) 
   {
      sumValue += o.price * o.amount;
      sumPrice += o.price;
   }
   return sumValue / sumPrice;

 }

CandleStick OrderBook::computeCandle(std::string timeStamp,
                        std::string product,
                        OrderBookType type) 
{
      CandleStick result{timeStamp, product, type};

      
      std::vector<OrderBookEntry> currentOrders = getOrders(type, product, timeStamp);
      std::vector<OrderBookEntry> previousOrders = getOrders(type, product, getPreviousTime(timeStamp));

      // High and low
      result.high = getHigherPrice(currentOrders);
      result.low =  getLowerPrice(currentOrders);

      // open and close     
      result.close = averagePrice(currentOrders);
      result.open =  averagePrice(previousOrders);

      return result;
}

std::vector<std::string> OrderBook::getKnownTimeStamps() 
{
   std::vector<std::string> timeStamps;
   std::map<std::string, bool> timeMap;
   for (OrderBookEntry& order: orders) 
   {
      timeMap[order.timestamp] = true;
   }
   for (const auto& e: timeMap) 
   {
      timeStamps.push_back(e.first);
   }
   return timeStamps;               
}

std::vector<CandleStick> OrderBook::computeCandles(std::string product, OrderBookType type) 
{
   std::vector<CandleStick> result;
   std::vector<std::string> timeStamps = getKnownTimeStamps();
   for (std::string& t: timeStamps) 
   {
     result.push_back(computeCandle(t, product, type));
  }
   return result;
}  

