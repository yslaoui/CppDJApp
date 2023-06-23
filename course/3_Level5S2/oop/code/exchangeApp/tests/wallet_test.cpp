// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

// app specific includes
#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include <fstream>
#include "../OrderBook.h"
#include "../Wallet.h"

class WalletTest : public CppUnit::TestFixture
{
    public:
        Wallet wallet{};


        void test_insertCurrency() 
        {    
            wallet.insertCurrency("DOGE", 100);
            CPPUNIT_ASSERT(wallet.containsCurrency("DOGE", 10));
        }

        /**Wallet contains 10 BTC, we exchange 1 BTC for 1 ETH*/
        void test_processSale() 
        {
            wallet.insertCurrency("BTC", 10);
            OrderBookEntry sale{1, 1, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bidsale, "user"};
            wallet.processSale(sale);
            CPPUNIT_ASSERT(wallet.containsCurrency("ETH", 1));
            CPPUNIT_ASSERT(wallet.containsCurrency("BTC", 9));
        }

};