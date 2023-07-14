
// g++ main.cpp -lcppunit

// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <fstream>

// App specific includes

#include "./CsvReader_test.cpp"
#include "./OrderBook_test.cpp"
#include "./wallet_test.cpp"
#include "./CandleStick_test.cpp"
#include "../CsvReader.h"
#include "../OrderBookEntry.h"


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

    // myrunner.addTest(new CppUnit::TestCaller<WalletTest> {
    // "test_processSale", 
    // &WalletTest::test_processSale 
    // });  
    
    // myrunner.addTest(new CppUnit::TestCaller<CandleStickTest> {
    // "test_constructor", 
    // &CandleStickTest::test_constructor 
    // });  
 
    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getPreviousTime", 
    // &OrderBookTest::test_getPreviousTime 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getKnownTimeStamps", 
    // &OrderBookTest::test_getKnownTimeStamps 
    // }); 

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_computeCandle", 
    // &OrderBookTest::test_computeCandle 
    // }); 
    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_computeCandles", 
    // &OrderBookTest::test_computeCandles 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getPosition", 
    // &OrderBookTest::test_getPosition 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_generateGrid", 
    // &OrderBookTest::test_generateGrid 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_lowestLow", 
    // &OrderBookTest::test_lowestLow 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_highestHigh", 
    // &OrderBookTest::test_highestHigh 
    // }); 


    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_computeNextFiveCandles", 
    // &OrderBookTest::test_computeNextFiveCandles 
    // });  

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_plotCandleSticks", 
    // &OrderBookTest::test_plotCandleSticks 
    // }); 

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_getVolume", 
    // &OrderBookTest::test_getVolume 
    // }); 

    // myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    // "test_lowestVolume", 
    // &OrderBookTest::test_lowestVolume 
    // }); 

    myrunner.addTest(new CppUnit::TestCaller<OrderBookTest> {
    "test_plotVolumes", 
    &OrderBookTest::test_plotVolumes 
    }); 



    myrunner.run();
}