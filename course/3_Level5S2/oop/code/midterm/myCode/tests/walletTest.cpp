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

class WalletTest : public CppUnit::TestFixture
{
    public:
        Wallet wallet{};


        void test_insertCurrency() 
        {    
            wallet.insertCurrency("DOGE", 100);
            CPPUNIT_ASSERT(wallet.containsCurrency("DOGE", 10));
        }

        void test_processSale() 
        {
            wallet.insertCurrency("BTC", 10);
            std::cout << "before" << std::endl;
            std::cout <<  wallet.toString() << std::endl; 
            OrderBookEntry sale{1, 1, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bidsale, "user"};
            std::cout << "after" << std::endl;
            wallet.processSale(sale);
            std::cout <<  wallet.toString() << std::endl; 
        }

};