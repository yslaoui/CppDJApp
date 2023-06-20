#pragma once
#include <vector>
#include <string>
#include "OrderBookEntry.h"


class OrderBook
{
   public:
   /** construct, reading a csv file */    
       OrderBook(std::string filename);   
   /** produces a list of unique products*/
       std::vector<std::string> getKnownProducts();
   /** Filters the orders based on critera*/
       std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                             std::string product,
                                             std::string timeStamp);
  
   /** returns the maximum price observed in a vector of an OrderBook Entry object*/  
       static double getHigherPrice(std::vector<OrderBookEntry> newOrders);

   /** returns the maximum price observed in a vector of an OrderBook Entry object*/  
       static double getLowerPrice(std::vector<OrderBookEntry> newOrders);
 
    /** Print an OrderBookEntry object */
      static void printOrderBookEntry(OrderBookEntry row);

    /** Returns the earliest time*/ 
        std::string getEarliestTime();   
    
    /** Return the next time frame after the time frame specified in the argument
     * If no next time frame is found, wrap around to the beginning of time
     * Uses the fact that the orders entries is already sorted by time
    */
    std::string getNextTime(std::string timeStamp);

    /** Insert an order into the order book*/
    void insertOrder(OrderBookEntry& order);

    /** Match bids and asks and return a vector of ssale orders, for a given product and time stamp*/
    std::vector<OrderBookEntry> matchOrders(std::string product, std::string timeStamp);

    /** Vector of OrderBookEntry objects, each representing one row in the CSV file*/ 
    std::vector<OrderBookEntry> orders;




};
