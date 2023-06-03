// g++ main.cpp -lcppunit

// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <fstream>

// App specific includes

#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include "CsvReader_test.cpp"
#include "OrderBook_test.cpp"

int main() 
{
    
    CppUnit::TextUi::TestRunner myrunner{};
    
    // *** CsvReader class tests // *** 
    myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
        "test_tokenize", 
        &CsvReaderTest::test_tokenize 
    });   

    myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    "test_stringsToOBE", 
    &CsvReaderTest::test_stringsToOBE 
    });   

    myrunner.addTest(new CppUnit::TestCaller<CsvReaderTest> {
    "test_readCSV", 
    &CsvReaderTest::test_readCSV 
    });

    // *** OrderBook class tests // *** 
    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_getKnownProducts", 
    &OrderBookTest::test_getKnownProducts 
    });

    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_getOrders", 
    &OrderBookTest::test_getOrders 
    });

    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_getHigherPrice", 
    &OrderBookTest::test_getHigherPrice 
    });

    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_getEarliestTime", 
    &OrderBookTest::test_getEarliestTime 
    });

    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_getNextTime", 
    &OrderBookTest::test_getNextTime 
    });

 
    myrunner.run();
}