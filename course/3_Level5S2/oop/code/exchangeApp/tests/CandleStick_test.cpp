// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <fstream>

// app specific includes
#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include "../OrderBook.h"
#include "../Wallet.h"
#include "../CandleStick.h"

class CandleStickTest : public CppUnit::TestFixture
{
    public:
        CandleStick candlestick{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
        void test_constructor() 
        {    
            std::cout << candlestick.timeStamp << std::endl;
            CPPUNIT_ASSERT( candlestick.timeStamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT( candlestick.product == "ETH/BTC");
            CPPUNIT_ASSERT( candlestick.orderType == OrderBookType::bid);
        }
};