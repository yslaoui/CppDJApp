// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

// app specific includes
#include "../CSVReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"

class OrderBookTest : public CppUnit::TestFixture
{
    public:
        OrderBook input{"../20200601.csv"};
        std::vector<OrderBookEntry> orders = input.getOrders();
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
            double result = OrderBook::getHighPrice(input4);
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
            int initialSize = orders.size();
            OrderBookEntry input2{5418.51724799, 0.00072134, "2020/03/17 17:01:35.103526", "BTC/USDT", OrderBookType::ask};
            input.insertOrder(input2);
            // Good practice: print the results first and see if they are as expected.    
            // std::cout << "input.orders[0].price " << input.orders[0].price << std::endl;
            // std::cout << "input.orders[1].price " << input.orders[1].price << std::endl;
            // std::cout << "input.orders[2].price " << input.orders[2].price << std::endl;            
            // std::cout << "input.orders[3].price " << input.orders[3].price << std::endl;

            CPPUNIT_ASSERT(orders.size() == initialSize + 1); 
            CPPUNIT_ASSERT(orders[0].price == 0.02187308);
            CPPUNIT_ASSERT(orders[1].price == 116.80745636);
            CPPUNIT_ASSERT(orders[2].price == 5418.51724799);
            CPPUNIT_ASSERT(orders[3].price == 0.0014);         
        }

        void test_comparePriceAsc() 
        {
            bool result = OrderBookEntry::compareByPriceAsc(orders[0], orders[1]);
            CPPUNIT_ASSERT(result == true);
        }        
        
        void test_comparePriceDesc() 
        {
            bool result = OrderBookEntry::compareByPriceDesc(orders[1], orders[2]);
            CPPUNIT_ASSERT(result == true);
        }

        void test_matchOrders() 
        {
            OrderBook input{"./matcherTest3.csv"};
            std::vector<OrderBookEntry> result = input.matchAsksToBids("ETH/BTC", "2020/03/17 17:01:24.884492");
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
};

