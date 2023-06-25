// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

// app specific includes
#include "../CSVReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"
#include "../MerkelMain.h"

class ExchangeAppTest : public CppUnit::TestFixture
{
    public:
        OrderBook input{"../orderBook.csv"};
        MerkelMain app{};
        void test_enterAsk() 
        {    
            /*
            app.enterAsk();

            std::vector<std::string> result = input.getKnownProducts(); 
            CPPUNIT_ASSERT(result[0] == "BTC/USDT");
            CPPUNIT_ASSERT(result[1] == "DOGE/BTC");
            CPPUNIT_ASSERT(result[2] == "DOGE/USDT");
            CPPUNIT_ASSERT(result[3] == "ETH/BTC");
            CPPUNIT_ASSERT(result[4] == "ETH/USDT");
            */
        }
};

