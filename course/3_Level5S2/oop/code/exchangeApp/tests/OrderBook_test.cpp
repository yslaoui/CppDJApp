// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

// app specific includes
#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"

class OrderBookTest : public CppUnit::TestFixture
{
    public:
        OrderBook input{"../orderBook.csv"};

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
            OrderBook input{"../orderBook.csv"};
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
};

