// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

// app specific includes
#include "../CSVReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"
#include "../Wallet.h"
#include "../CandleStick.h"

class CandleStickTest : public CppUnit::TestFixture
{
    public:
        CandleStick candlestick{"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::ask};
        void test_constructor() 
        {    
            std::cout << candlestick.timeStamp << std::endl;
            CPPUNIT_ASSERT( candlestick.timeStamp == "2020/06/01 11:57:30.328127");
            CPPUNIT_ASSERT( candlestick.product == "ETH/BTC");
            CPPUNIT_ASSERT( candlestick.orderType == OrderBookType::ask);
            

        }
};