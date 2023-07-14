#include "OrderBook.h"
#include "CsvReader.h"
#include <map>
#include <algorithm> // for std::sort
#include "ExchangeApp.h"
#include <cmath>

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


double OrderBook::getHigherPrice(std::vector<OrderBookEntry>& orders_sub) 
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

double OrderBook::getLowerPrice(std::vector<OrderBookEntry>& orders_sub) 
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

std::string OrderBook::getNextTime(std::string& timeStamp) 
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


std::vector<OrderBookEntry> OrderBook::matchOrders(std::string& product, std::string& timeStamp) 
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

std::string OrderBook::getPreviousTime(std::string& timeStamp) 
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


 double OrderBook::averagePrice(std::vector<OrderBookEntry>& orderEntry) 
 {
   double sumValue  = 0;
   double sumAmount = 0;

   for (OrderBookEntry& o: orderEntry) 
   {
      sumValue  += o.price * o.amount;
      sumAmount += o.amount;
   }
   return sumValue / sumAmount;

 }

CandleStick OrderBook::computeCandle(std::string& timeStamp,
                        std::string& product,
                        OrderBookType& type) 
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

      // volume
      result.volume = getVolume(currentOrders);

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

std::vector<CandleStick> OrderBook::computeCandles(std::string& product, OrderBookType& type) 
{
   std::vector<CandleStick> result;
   std::vector<std::string> timeStamps = getKnownTimeStamps();

   for (std::string& t: timeStamps) 
   {
     result.push_back(computeCandle(t, product, type));
   }
   return result;
}  

int OrderBook::getPosition(double& value, double& low, double& high, int& scaleMin, int& scaleMax)  
   {
      if (low > high || value < low || value > high) std::cout << "Incorrect input" << std::endl;
      double range = high - low;
      double normalizedValue = (value - low) / range; // maps value in [0,1]
      int scaledValue = scaleMin + floor(normalizedValue * (scaleMax - scaleMin)); // maps value in [scaleMin, scaleMax]
      return scaledValue;
   }



std::vector<std::vector<char>> OrderBook::generateGrid(int& rows, int& columns) 
{
   std::vector<std::vector<char>> result(rows, std::vector<char>(columns,'|'));
   return result;
}

void OrderBook::plotGrid(std::vector<std::vector<char>>& grid)
{
   int rows = grid.size();
   int columns = grid[0].size();
   for (int i=rows-1; i>=0; --i) 
   {
         for (int j=0; j<columns; ++j) 
         {
            std::cout << " "<< grid[i][j] << " ";
         }
         std::cout << std::endl;
   }     
   // for (int j=0; j< columns; ++j) 
   // {
   //    std::cout << j << " ";
   // }
   std::cout << std::endl;

}

double OrderBook::lowestLow(std::vector<CandleStick>& candles) 
{
   double minPrice = std::numeric_limits<double>::max(); 
   for (CandleStick& c: candles) 
   {
      // std::cout << "the low is " << c.low << std::endl;
      minPrice = std::min(minPrice, c.low);
   }
   return minPrice;
   
}

double OrderBook::highestHigh(std::vector<CandleStick>& candles) 
{
   double maxPrice = std::numeric_limits<double>::lowest(); 
   for (CandleStick& c: candles) 
   {
      //  std::cout << "the high is " << c.high << std::endl;
      maxPrice = std::max(maxPrice, c.high);
   }
   return maxPrice;
   
}

 void OrderBook::plotCandleSticks(std::vector<CandleStick>& candles, int& desiredHeight) 
 {
   
   // int columns = 10;
   int columns = candles.size();
   int initial = 0;
   int rows = desiredHeight;
   std::vector<std::vector<char>> grid = OrderBook::generateGrid(rows, columns);
   double lowestLow = OrderBook::lowestLow(candles);
   double highestHigh = OrderBook::highestHigh(candles);
   int open;
   int close;
   int high;
   int low;
   std::cout << "The lowest low across all products is " << lowestLow << std::endl;
   std::cout << "The highest high across all products is " << highestHigh << std::endl;
   for (int i=0; i< columns; ++i) 
   {
      open  = OrderBook::getPosition(candles[i].open,  lowestLow, highestHigh, initial, desiredHeight);
      close = OrderBook::getPosition(candles[i].close, lowestLow, highestHigh, initial, desiredHeight);
      high  = OrderBook::getPosition(candles[i].high,  lowestLow, highestHigh, initial, desiredHeight);
      low   = OrderBook::getPosition(candles[i].low,   lowestLow, highestHigh, initial, desiredHeight);
      grid[open][i]  = 'o';
      grid[close][i] = 'c';
      grid[high-1][i]  = 'h';
      grid[low][i]   = 'l';
      for (int j=0; j< rows; ++j) 
      {
         if ((j>=open && j <=close) || (j<=open && j >=close)) grid[j][i] = 61;
         if ((j < low)||(j >= high)) grid[j][i] = ' ';
         if ((j == low) || (j == high-1)) grid[j][i] = '|';
         

      }
      // std::cout << "open: " << candles[i].open <<" close: " << candles[i].close <<" high: " << candles[i].high <<" low: " << candles[i].low << " time: " << candles[i].timeStamp << std::endl; 
      // std::cout << "iteration " << i << "done" << std::endl;
   }
   std::cout << "PRICE---------------------------------------" << candles[0].product << "------------------------------------" << std::endl;
   
   OrderBook::plotGrid(grid);
   std::string firstDate = candles[0].timeStamp;
   std::string lastDate = candles[candles.size()-1].timeStamp;
   std::cout << "TIMEFRAME-------------" << firstDate << " - " << lastDate << "------------" << std::endl;
}

std::vector<std::string>  OrderBook::nextFiveDates(std::string timeStamp) 
{
   std::vector<std::string> result;
   int count = 0;
   std::vector<std::string> timestamps = getKnownTimeStamps();
   // Find the index of timeStamp argument
   int currentIndex = 0;
   while (timeStamp != timestamps[currentIndex]) 
   {
      currentIndex += 1;
   }

   // push the next 5 dates to the result
   while (count < 30) 
   {
      result.push_back(timestamps[currentIndex]);
      currentIndex++;
      count++;
   }
   return result;
}

std::vector<CandleStick> OrderBook::computeNextFiveCandles(std::string& product, OrderBookType& type, std::string& timestamp) 
{
   std::vector<CandleStick> result;
   std::vector<std::string> timeStamps = nextFiveDates(timestamp);

   for (std::string& t: timeStamps) 
   {
     result.push_back(computeCandle(t, product, type));
   }
   return result;
} 

double OrderBook::getVolume(std::vector<OrderBookEntry>& orderEntry) 
{
  
   double totalAmount  = 0;
   
   for (OrderBookEntry& o: orderEntry) 
   {
      totalAmount += o.amount;
   }
   return totalAmount;
  
}

double OrderBook::lowestVolume(std::vector<CandleStick>& candles) 
{
   double minVolume = std::numeric_limits<double>::max(); 
   for (CandleStick& c: candles) 
   {
      // std::cout << "the low is " << c.low << std::endl;
      minVolume = std::min(minVolume, c.volume);
   }
   return minVolume;
}

double OrderBook::highestVolume(std::vector<CandleStick>& candles) 
{
   double maxVolume = std::numeric_limits<double>::lowest(); 
   for (CandleStick& c: candles) 
   {
      //  std::cout << "the high is " << c.high << std::endl;
      maxVolume = std::max(maxVolume, c.volume);
   }
   return maxVolume;
}

void OrderBook::plotVolumes(std::vector<CandleStick>& candles, int& desiredHeight) 
{
   // int columns = 10;
   int columns = candles.size();
   int initial = 0;
   int rows = desiredHeight;
   std::vector<std::vector<char>> grid = OrderBook::generateGrid(rows, columns);
   double lowestLow = lowestVolume(candles);
   double highestHigh = highestVolume(candles);
   int volume;
   std::cout << "The lowest volume all products is " << lowestLow << std::endl;
   std::cout << "The highest volume across all products is " << highestHigh << std::endl;
   for (int i=0; i< columns; ++i) 
   {
      volume  = getPosition(candles[i].volume, lowestLow, highestHigh, initial, desiredHeight);
      for (int j=0; j< rows; ++j) 
      {
         if ( j <= volume) grid[j][i] = 61;
      }  
   }
   std::cout << "VOLUME---------------------------------------" << candles[0].product << "------------------------------------" << std::endl;
   
   OrderBook::plotGrid(grid);
   std::string firstDate = candles[0].timeStamp;
   std::string lastDate = candles[candles.size()-1].timeStamp;
   std::cout << "TIMEFRAME-------------" << firstDate << " - " << lastDate << "------------" << std::endl;

}




