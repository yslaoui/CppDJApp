#pragma once
#include <vector>
#include <string>
#include "OrderBookEntry.h"
#include "CandleStick.h"

// Forward declaration of the CandleStick class to avoid circular problem with OrderBook
class CandleStick;

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
        static double getHigherPrice(std::vector<OrderBookEntry>& newOrders);

   /** returns the maximum price observed in a vector of an OrderBook Entry object*/  
        static double getLowerPrice(std::vector<OrderBookEntry>& newOrders);

    /** Print an OrderBookEntry object */
        static void printOrderBookEntry(OrderBookEntry row);

    /** Returns the earliest time*/ 
        std::string getEarliestTime();   
    
    /** Return the next time frame after the time frame specified in the argument
     * If no next time frame is found, wrap around to the beginning of time
     * Uses the fact that the orders entries is already sorted by time
    */
        std::string getNextTime(std::string& timeStamp);

    /** Return the previous time frame before the time frame specified in the argument
      * If no previous time frame is found, returns the first timeStamp
    */
        std::string getPreviousTime(std::string& timeStamp);

    /** Insert an order into the order book*/
        void insertOrder(OrderBookEntry& order);

    /** Match bids and asks and return a vector of ssale orders, for a given product and time stamp*/
        std::vector<OrderBookEntry> matchOrders(std::string& product, std::string& timeStamp);

    /** Getter met
     * hod for the orders data member */
        std::vector<OrderBookEntry> getterOrders();

    /** Helper function used to compute open and close prices in candlesticks.  */
    static double averagePrice(std::vector<OrderBookEntry>& orderEntry);

    /** Computes attributes of candle that are not passed in Candle constructor*/
        // CandleStick computeCandle(std::string timeStamp, std::string product, OrderBookType type);
    CandleStick computeCandle(std::string& timeStamp,
                              std::string& product,
                              OrderBookType& orderType);

    /** Computes a vector of unique timestamps in the orderbook*/
    std::vector<std::string> getKnownTimeStamps(); 

    /** Computes candleStick data*/
    std::vector<CandleStick> computeCandles(std::string& product, OrderBookType& type); 

    /** Computes candleStick data for the next five dates after timestam*/
    std::vector<CandleStick> computeNextFiveCandles(std::string& product, OrderBookType& type, std::string& timestamp); 



    /** helper function computes position of value argument in candleStick between 0 and height where height is the height of the plot*/
    static int getPosition(double& value, double& low, double& high, int& scaleMin, int& scaleMax); 

    static std::vector<std::vector<char>> generateGrid(int& rows, int& columns);

    static void plotGrid(std::vector<std::vector<char>>& grid);

    /** Returns the lowest low value in a vector of candle sticks*/
    static double lowestLow(std::vector<CandleStick>& candles);

    /** Returns the highest high value in a vector of candle sticks*/
    static double highestHigh(std::vector<CandleStick>& candles);

    /** Plot candle sticks*/
    static void plotCandleSticks(std::vector<CandleStick>& candles, int& desiredHeight);


    /** return vector of 5 dates after the argument date string*/
    std::vector<std::string> nextFiveDates(std::string timeStamp);

    /** Compute the sum of amounts in a vector of OrderBookEntry objects */
    static double getVolume(std::vector<OrderBookEntry>& orderEntry);

    /** Returns the lowest  volume in a vector of candle sticks*/
    static double lowestVolume(std::vector<CandleStick>& candles);

    /** Returns the highest  volume in a vector of candle sticks*/
    static double highestVolume(std::vector<CandleStick>& candles);

    /** Plot volume*/
    static void plotVolumes(std::vector<CandleStick>& candles, int& desiredHeight);





    private: 
    /** Vector of OrderBookEntry objects, each representing one row in the CSV file*/ 
        std::vector<OrderBookEntry> orders;
};

