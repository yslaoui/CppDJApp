// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cmath>

// app specific includes
#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"
#include "../CandleStick.h"

class OrderBookTest : public CppUnit::TestFixture
{
    public:
        // OrderBook input{"./smallCourseFile.csv"};
        OrderBook input{"../bigMidtermFile.csv"};
        std::vector<OrderBookEntry> orders = input.getterOrders();
        


        void test_getKnownProducts() 
        {    
            std::vector<std::string> result = input.getKnownProducts(); 
            CPPUNIT_ASSERT(result[0] == "BTC/USDT");
            CPPUNIT_ASSERT(result[1] == "DOGE/BTC");
            CPPUNIT_ASSERT(result[2] == "DOGE/USDT");
            CPPUNIT_ASSERT(result[3] == "ETH/BTC");
            CPPUNIT_ASSERT(result[4] == "ETH/USDT");
        }

        void test_getOrders() 
        {
            OrderBookType input1 = OrderBookType::ask;
            std::string input2 = "BTC/USDT";
            std::string input3 = "2020/03/17 17:01:24.884492";
            std::vector<OrderBookEntry> result = input.getOrders(input1, input2, input3);
            CPPUNIT_ASSERT(result[0].product == "BTC/USDT");
            CPPUNIT_ASSERT(result[0].timestamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result[0].orderType == OrderBookType::ask);
        }

        void test_getHigherPrice() 
        {
            OrderBookType input1 = OrderBookType::ask;
            std::string input2 = "BTC/USDT";
            std::string input3 = "2020/03/17 17:01:45.111661";
            std::vector<OrderBookEntry> input4 = input.getOrders(input1, input2, input3);
            double result = OrderBook::getHigherPrice(input4);
            CPPUNIT_ASSERT(result == 5463.22 );
            
        }

        void test_getEarliestTime() 
        {
            std::string result = input.getEarliestTime();
            CPPUNIT_ASSERT(result == "2020/03/17 17:01:24.884492");

        }

        void test_getNextTime() 
        {
            std::string firstTime = input.getEarliestTime();
            std::string lastTime =  "2020/03/17 17:02:00.124758";   
            std::string time1 =             // CPPUNIT_ASSERT(result[0] == "2020/03/17 17:01:24.884492");
            // CPPUNIT_ASSERT(result[1] == "2020/03/17 17:01:30.099017");
            // CPPUNIT_ASSERT(result[2] == "2020/03/17 17:01:35.103526");
            // CPPUNIT_ASSERT(result[3] == "2020/03/17 17:01:40.107326");
            // CPPUNIT_ASSERT(result[4] == "2020/03/17 17:01:45.111661");
            // CPPUNIT_ASSERT(result[5] == "2020/03/17 17:01:50.116610");
            // CPPUNIT_ASSERT(result[6] == "2020/03/17 17:01:55.120438");
 "2020/03/17 17:01:30.099017";   
            std::string time2 =  "2020/03/17 17:01:35.103526";
            std::string time3 =  "2020/03/17 17:01:40.107326";
            std::string time4 =  "2020/03/17 17:01:50.116610";
            
            CPPUNIT_ASSERT(input.getNextTime(lastTime) == firstTime);
            CPPUNIT_ASSERT(input.getNextTime(firstTime) == "2020/03/17 17:01:30.099017");
            CPPUNIT_ASSERT(input.getNextTime(time1) == "2020/03/17 17:01:35.103526");
            CPPUNIT_ASSERT(input.getNextTime(time2) == "2020/03/17 17:01:40.107326");
            CPPUNIT_ASSERT(input.getNextTime(time3) == "2020/03/17 17:01:45.111661");

        }

        void test_insertOrder() 
        {
            OrderBookEntry input2{100, 101, "2020/03/17 17:01:35.103526", "new/new", OrderBookType::ask};
            input.insertOrder(input2);
            // Good practice: print the results first and see if they are as expected.    
            std::vector<OrderBookEntry> findOrder = input.getOrders(input2.orderType, input2.product, input2.timestamp);
            std::cout << "findOrder[0].price" << findOrder[0].price << std::endl;
            std::cout << "findOrder[0].amount" << findOrder[0].amount << std::endl;
            std::cout << "findOrder[0].product" << findOrder[0].product << std::endl;            

            // CPPUNIT_ASSERT(orders.size() == initialSize + 1); 
            CPPUNIT_ASSERT(findOrder[0].price == 100);
            CPPUNIT_ASSERT(findOrder[0].amount == 101);
            CPPUNIT_ASSERT(findOrder[0].product == "new/new");         
        }

        void test_comparePriceAsc() 
        {
            bool result = OrderBookEntry::comparePriceAsc(orders[0], orders[1]);
            CPPUNIT_ASSERT(result == false);
        }        
        
        void test_comparePriceDesc() 
        {
            bool result = OrderBookEntry::comparePriceDesc(orders[0], orders[1]);
            CPPUNIT_ASSERT(result == true);
        }

        void test_matchOrders() 
        {
            OrderBook input4{"./matcherTest.csv"};
            std::string product = "ETH/BTC";
            std::string timeStamp = "2020/03/17 17:01:24.884492";
            std::vector<OrderBookEntry> result = input4.matchOrders(product, timeStamp);
            std::cout <<  "test_matchOrders(): size of sales  " << result.size() << std::endl; 
            for (OrderBookEntry& sale: result) 
            {
                std::cout <<  "price  " << sale.price << std::endl; 
                std::cout <<  "amount  " << sale.amount << std::endl; 
            }
            
            CPPUNIT_ASSERT(result[0].price == 10);
            CPPUNIT_ASSERT(result[0].amount == 0.5); // highest bid gets priority
            CPPUNIT_ASSERT(result[1].price == 10); 
            CPPUNIT_ASSERT(result[1].amount == 0.1);
            CPPUNIT_ASSERT(result[2].price == 10); 
            CPPUNIT_ASSERT(result[2].amount == 0.4);
        }        

        void test_getPreviousTime() 
        {
            std::string origin = input.getEarliestTime();
            std::string intermediaryTime = "2020/03/17 17:01:30.099017"; 
            std::string result1 = input.getPreviousTime(intermediaryTime);
            std::string result2 = input.getPreviousTime(origin);
            
            CPPUNIT_ASSERT(result1 == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result2 == origin);
        }

        void test_computeCandle() 
        {

            for (const auto & t: input.getKnownTimeStamps()) 
            {
                for (const auto & p: input.getKnownProducts()) 
                {
                    std::string product = p;
                    std::string timeStamp = t;
                    OrderBookType type = OrderBookType::ask;
                    CandleStick myCandle = input.computeCandle(timeStamp, product, type);
                    
                    CPPUNIT_ASSERT(myCandle.timeStamp == t);
                    CPPUNIT_ASSERT(myCandle.product == p);
                    CPPUNIT_ASSERT(myCandle.orderType == OrderBookType::ask);
                }
            }     
            std::string timeStamp = "2020/03/17 17:01:35.103526";
            std::string product = "BTC/USDT";
            OrderBookType type  = OrderBookType::ask;
            CandleStick candle = input.computeCandle(timeStamp, product, type);
            CPPUNIT_ASSERT( candle.timeStamp == timeStamp);
            CPPUNIT_ASSERT( candle.product == product);
            CPPUNIT_ASSERT( candle.orderType == type);
            CPPUNIT_ASSERT( candle.high == 5463.22);
            CPPUNIT_ASSERT( candle.low == 5360.03200001);
            std::cout << "candle.close" << candle.close << std::endl;
            std::cout << "candle.open" << candle.open << std::endl;
            CPPUNIT_ASSERT( abs(candle.close - 5394.07) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
            CPPUNIT_ASSERT( abs(candle.open  - 5394.38) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
            std::cout << "Printing volume" << std::endl;
            std::cout << candle.volume << std::endl;
            CPPUNIT_ASSERT(candle.volume == 39.59567974);
            // testing last date
            // std::string timeStamp = "2020/03/17 17:02:00.124758";
            // std::string product = "DOGE/BTC";
            // OrderBookType type  = OrderBookType::ask;
            // CandleStick candle = input.computeCandle(timeStamp, product, type);
            // CPPUNIT_ASSERT( candle.timeStamp == "2020/03/17 17:02:00.124758");
            // CPPUNIT_ASSERT( candle.product == "DOGE/BTC");
            // CPPUNIT_ASSERT( candle.orderType == OrderBookType::ask);
            // CPPUNIT_ASSERT( candle.high == 0.0000008);
            // CPPUNIT_ASSERT( candle.low == 0.00000031);
            // std::cout << "candle.close " <<  candle.close << std::endl;
            // std::cout << "candle.open " <<   candle.open << std::endl;
            // CPPUNIT_ASSERT( abs(candle.close - 0.7913) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
            // CPPUNIT_ASSERT( abs(candle.open - 0.6746) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
        
        }

        void test_getKnownTimeStamps() 
        {
            std::vector<std::string> result = input.getKnownTimeStamps();
            std::cout << "THE KNOWN TIMESTAMPS ARE" << std::endl;
            for (int i=0; i< result.size(); ++i) 
            {
                std::cout << result[i] << std::endl;
            }
            CPPUNIT_ASSERT(result[0] == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result[1] == "2020/03/17 17:01:30.099017");
            CPPUNIT_ASSERT(result[2] == "2020/03/17 17:01:35.103526");
            CPPUNIT_ASSERT(result[3] == "2020/03/17 17:01:40.107326");
            CPPUNIT_ASSERT(result[4] == "2020/03/17 17:01:45.111661");
            CPPUNIT_ASSERT(result[5] == "2020/03/17 17:01:50.116610");
            CPPUNIT_ASSERT(result[6] == "2020/03/17 17:01:55.120438");
        }

        void test_computeCandles() 
        {
            // std::string product = "DOGE/BTC";
            // OrderBookType type  = OrderBookType::ask;
            std::string product = "BTC/USDT";
            OrderBookType type  = OrderBookType::ask;
            std::vector<CandleStick> result = input.computeCandles(product, type);
            // Testing timestamps
            for (int i=0; i<result.size(); ++i) 
            {
                CPPUNIT_ASSERT(result[i].timeStamp == input.getKnownTimeStamps()[i]);
            }
            // testing products
            for (int i=0; i<result.size(); ++i) {
                std::vector<OrderBookEntry> testOrders = input.getOrders(type, product, result[i].timeStamp);
                CPPUNIT_ASSERT(result[i].high == input.getHigherPrice(testOrders));
            }
        }

        void test_getPosition() 
        {
            std::vector<double> inputs = {101, 109, 110, 189, 200};
            std::vector<int> result(5);
            double value = 150;
            double low = 100;
            double high = 200;
            int scaleMin = 0;
            int scaleHigh = 10;
            for (int i=0;  i< result.size(); ++i) 
            {
                result[i] = OrderBook::getPosition(inputs[i], low, high, scaleMin, scaleHigh); 
            }   
            std::cout << "result[4] " << result[4] << std::endl;
            CPPUNIT_ASSERT(result[0] == scaleMin);
            CPPUNIT_ASSERT(result[1] == 0);
            CPPUNIT_ASSERT(result[2] == 1);
            CPPUNIT_ASSERT(result[3] == 8);
            CPPUNIT_ASSERT(result[4] == scaleHigh);
        }

        void test_generateGrid() 
        {
            int rows = 5;
            int columns = 5;
            std::vector<std::vector<char>>  grid =  OrderBook::generateGrid(rows, columns);
            grid[2][3] = 'o';
            std::cout << std::endl;
            OrderBook::plotGrid(grid);
        }

        void test_lowestLow() 
        {
    
            std::vector<CandleStick> candlesAsk;
            std::vector<CandleStick> candlesBid;
            double lowestaskLow;
            double lowestbidLow;
            std::vector<std::string> products = input.getKnownProducts();
            for (std::string& p: products) 
            {
                OrderBookType ask = OrderBookType::ask;
                OrderBookType bid = OrderBookType::bid;
                candlesAsk = input.computeCandles(p, ask);
                candlesBid = input.computeCandles(p, bid);
                lowestaskLow = OrderBook::lowestLow(candlesAsk);
                lowestbidLow = OrderBook::lowestLow(candlesBid);
                std::cout << "product " << p << "has lowest ask " << lowestaskLow << "and lowest bid "  << lowestbidLow << std::endl;
            }
        }

        void test_highestHigh() 
        {
    
            std::vector<CandleStick> candlesAsk;
            std::vector<CandleStick> candlesBid;
            double highestaskHigh;
            double highestbidHigh;
            std::vector<std::string> products = input.getKnownProducts();
            for (std::string& p: products) 
            {
                OrderBookType ask = OrderBookType::ask;
                OrderBookType bid = OrderBookType::bid;
                candlesAsk = input.computeCandles(p, ask);
                candlesBid = input.computeCandles(p, bid);
                highestaskHigh = OrderBook::highestHigh(candlesAsk);
                highestbidHigh = OrderBook::highestHigh(candlesBid);
                std::cout << "product " << p << "has highest ask " << highestaskHigh << "and highest bid "  << highestbidHigh << std::endl;
            }
        }

        void test_plotCandleSticks() 
        {
            int test_index = 1;
            std::vector<std::string> timestamps = input.getKnownTimeStamps();
            int desiredHeight = 20; 
            OrderBookType type  = OrderBookType::bid;
            for (std::string& p: input.getKnownProducts()) 
            {
                std::vector<CandleStick> candles = input.computeNextFiveCandles(p, type, timestamps[test_index]);
                std::cout << "**************************************** "  << std::endl;   
                std::cout << "Candle sticks for product " << p << std::endl;
                std::cout << "**************************************** "  << std::endl;
                OrderBook::plotCandleSticks(candles, desiredHeight);                
            }
        }

        void test_nextFiveDates() 
        {
            int test_index = 2;
            std::vector<std::string> timestamps = input.getKnownTimeStamps();
            std::vector<std::string> result = input.nextFiveDates(timestamps[test_index]);
            
            CPPUNIT_ASSERT(result.size() == 5);
            CPPUNIT_ASSERT(result[0] == timestamps[test_index]);
            CPPUNIT_ASSERT(result[1] == timestamps[test_index + 1]);
            CPPUNIT_ASSERT(result[2] == timestamps[test_index + 2]);
            CPPUNIT_ASSERT(result[3] == timestamps[test_index + 3]);
            CPPUNIT_ASSERT(result[4] == timestamps[test_index + 4]);
        }

        void test_computeNextFiveCandles() 
        {
            int test_index = 1;
            std::vector<std::string> timestamps = input.getKnownTimeStamps();
            std::string product = "ETH/BTC";
            OrderBookType type = OrderBookType::ask;
            std::vector<CandleStick> result = input.computeNextFiveCandles(product, type, timestamps[test_index]);
            std::cout << "test_computeNextFiveCandles" << std::endl;
            std::cout << "Hi" << std::endl;
            for (CandleStick& c: result) 
            {                    
                std::cout << c.timeStamp << std::endl;
            }
            CPPUNIT_ASSERT(result.size() == 5);
            for (int i=0; i < result.size(); ++i) 
            {
                CPPUNIT_ASSERT(result[i].timeStamp == timestamps[test_index + i]);
            }
            
        }

        void test_getVolume() 
        {
            
            OrderBookType type = OrderBookType::ask;
            std::string product = "BTC/USDT";
            std::string timeStamp = "2020/03/17 17:01:24.884492";
            std::vector<OrderBookEntry> currentOrders = input.getOrders(type, product, timeStamp);
            CPPUNIT_ASSERT(OrderBook::getVolume(currentOrders) == 33.33036439);   
        }

       void test_lowestVolume()  
        { 

            int test_index = 1;
            std::vector<std::string> timestamps = input.getKnownTimeStamps();
            std::string product = "ETH/BTC";
            OrderBookType type = OrderBookType::ask;
            std::vector<CandleStick> candles = input.computeNextFiveCandles(product, 
                                                                    type, 
                                                                    timestamps[test_index]);
            double lowestVolume = OrderBook::lowestVolume(candles);
            double highestVolume = OrderBook::highestVolume(candles);
            
            CPPUNIT_ASSERT(abs(lowestVolume - 921.831) < 0.1 );
            CPPUNIT_ASSERT(abs(highestVolume - 1131.44) < 0.1 );


        }

        void test_plotVolumes() 
        {
            int test_index = 1;
            std::vector<std::string> timestamps = input.getKnownTimeStamps();
            int desiredHeight = 20; 
            OrderBookType type  = OrderBookType::bid;
            for (std::string& p: input.getKnownProducts()) 
            {
                std::vector<CandleStick> candles = input.computeNextFiveCandles(p, type, timestamps[test_index]);
                std::cout << "**************************************** "  << std::endl;   
                std::cout << "Candle sticks for product " << p << std::endl;
                std::cout << "**************************************** "  << std::endl;
                OrderBook::plotVolumes(candles, desiredHeight);                
            }
        }
};

/*
BTC/USDT 
DOGE/BTC
DOGE/USDT
ETH/BTC
ETH/USD
*/