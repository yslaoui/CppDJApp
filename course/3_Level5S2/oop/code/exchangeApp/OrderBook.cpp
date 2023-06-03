#include "OrderBook.h"
#include "CsvReader.h"
#include <map>

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


void printOrderBookEntry(OrderBookEntry row) 
      {
         std::cout << row.amount << std::endl;
         std::cout << row.price << std::endl;
         std::cout << row.product << std::endl;
         std::cout << row.timestamp << std::endl;

 }
   



