// g++ main.cpp -lcppunit

// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <fstream>

// App specific includes

#include "../CSVReader.h"
#include "../OrderBookEntry.h"
#include "OrderBook_test.cpp"
#include "walletTest.cpp"
#include "CandleStick_test.cpp"

int main() 
{
 
    CppUnit::TextUi::TestRunner myrunner{};
    

    // // *** CsvReader class tests // *** 
    // myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    //     "test_tokenize", 
    //     &CsvReaderTest::test_tokenize 
    // });   

    // myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    // "test_stringsToOBE", 
    // &CsvReaderTest::test_stringsToOBE 
    // });   

    // myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    // "test_readCSV", 
    // &CsvReaderTest::test_readCSV 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    // "test_stringsToOBEStrings", 
    // &CsvReaderTest::test_stringsToOBEStrings 
    // });

    // // *** OrderBook class tests // *** 
    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getKnownProducts", 
    // &OrderBookTest::test_getKnownProducts 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getOrders", 
    // &OrderBookTest::test_getOrders 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getHigherPrice", 
    // &OrderBookTest::test_getHigherPrice 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getEarliestTime", 
    // &OrderBookTest::test_getEarliestTime 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getNextTime", 
    // &OrderBookTest::test_getNextTime 
    // });
    
    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_insertOrder", 
    // &OrderBookTest::test_insertOrder 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_comparePriceAsc", 
    // &OrderBookTest::test_comparePriceAsc 
    // });

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_comparePriceDesc", 
    // &OrderBookTest::test_comparePriceDesc 
    // });    

    // myrunner.addTest(new CppUnit::TestCaller<WalletTest> {
    // "test_insertCurrency", 
    // &WalletTest::test_insertCurrency 
    // });  
    
    

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_matchOrders", 
    // &OrderBookTest::test_matchOrders 
    // });  

    myrunner.addTest(new CppUnit::TestCaller<CandleStickTest> {
    "test_processSale", 
    &CandleStickTest::test_constructor 
    });  

    myrunner.run();
}