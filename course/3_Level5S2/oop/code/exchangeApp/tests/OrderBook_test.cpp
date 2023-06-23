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
        OrderBook input{"../orderBook.csv"};
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
            CPPUNIT_ASSERT(input.getNextTime(lastTime) == firstTime);
            CPPUNIT_ASSERT(input.getNextTime(firstTime) == "2020/03/17 17:01:30.099017");
            CPPUNIT_ASSERT(input.getNextTime("2020/03/17 17:01:30.099017") == "2020/03/17 17:01:35.103526");
            CPPUNIT_ASSERT(input.getNextTime("2020/03/17 17:01:35.103526") == "2020/03/17 17:01:40.107326");
            CPPUNIT_ASSERT(input.getNextTime("2020/03/17 17:01:40.107326") == "2020/03/17 17:01:45.111661");
            CPPUNIT_ASSERT(input.getNextTime("2020/03/17 17:01:45.111661") == "2020/03/17 17:01:50.116610");
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
            std::vector<OrderBookEntry> result = input4.matchOrders("ETH/BTC", "2020/03/17 17:01:24.884492");
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
            std::string timeStamp = "2020/03/17 17:01:35.103526";
            std::string product = "BTC/USDT";
            OrderBookType type  = OrderBookType::ask;
            CandleStick candle = input.computeCandle(timeStamp, product, type);
            CPPUNIT_ASSERT( candle.timeStamp == "2020/03/17 17:01:35.103526");
            CPPUNIT_ASSERT( candle.product == "BTC/USDT");
            CPPUNIT_ASSERT( candle.orderType == OrderBookType::ask);
            CPPUNIT_ASSERT( candle.high == 5463.22);
            CPPUNIT_ASSERT( candle.low == 5360.03200001);
            CPPUNIT_ASSERT( abs(candle.close - 0.7913) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
            CPPUNIT_ASSERT( abs(candle.open - 0.6746) < 0.1 ); // value computed from excel, because of rounding errors ABS is better than ==
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
            CPPUNIT_ASSERT(result[0] == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result[1] == "2020/03/17 17:01:30.099017");
            CPPUNIT_ASSERT(result[2] == "2020/03/17 17:01:35.103526");
            CPPUNIT_ASSERT(result[3] == "2020/03/17 17:01:40.107326");
            CPPUNIT_ASSERT(result[4] == "2020/03/17 17:01:45.111661");
            CPPUNIT_ASSERT(result[5] == "2020/03/17 17:01:50.116610");
            CPPUNIT_ASSERT(result[6] == "2020/03/17 17:01:55.120438");
            CPPUNIT_ASSERT(result[7] == "2020/03/17 17:02:00.124758");
        }

        void test_computeCandles() 
        {
            std::string product = "DOGE/BTC";
            OrderBookType type  = OrderBookType::ask;
            std::vector<CandleStick> result = input.computeCandles(product, type);
            // Testing timestamps
            for (int i=0; i<result.size(); ++i) 
            {
                CPPUNIT_ASSERT(result[i].timeStamp == input.getKnownTimeStamps()[i]);
            }
            // testing products
            for (int i=0; i<result.size(); ++i) 
            {
                CPPUNIT_ASSERT(result[i].product == product);
            }
            // testing order types
            for (int i=0; i<result.size(); ++i) 
            {
                CPPUNIT_ASSERT(result[i].orderType == type);
            }
            // testing high
            for (int i=0; i<result.size(); ++i) 
            {   

                CPPUNIT_ASSERT(result[i].high == input.getHigherPrice(input.getOrders(type, product, result[i].timeStamp)));
            }

        }
};

