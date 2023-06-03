// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


// app specific includes


#include "../CsvReader.h"
#include "../OrderBookEntry.h"
#include <fstream>

class CsvReaderTest : public CppUnit::TestFixture 
{
    public: 
        void test_tokenize() 
        {
            std::string csvLine = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
            std::vector<std::string> result = CsvReader::tokenize(csvLine, ',');
            CPPUNIT_ASSERT(result[0] == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result[1] == "ETH/BTC");
            CPPUNIT_ASSERT(result[2] == "bid");
            CPPUNIT_ASSERT(result[3] == "0.02187308");
            CPPUNIT_ASSERT(result[4] == "7.44564869");    
        }

        void test_stringsToOBE() 
        {
            std::string csvLine = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
            std::vector<std::string> input = CsvReader::tokenize(csvLine, ',');
            OrderBookEntry output = CsvReader::stringsToOBE(input);
            CPPUNIT_ASSERT(output.timestamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(output.product == "ETH/BTC");
            CPPUNIT_ASSERT(output.orderType == OrderBookType::bid);
            CPPUNIT_ASSERT(output.price == 0.02187308);
            CPPUNIT_ASSERT(output.amount == 7.44564869);
        }

        void test_readCSV() 
        {
            std::string input = "../orderBook.csv";
            std::vector<OrderBookEntry> output = CsvReader::readCSV(input);
            CPPUNIT_ASSERT(output[0].timestamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(output[0].product == "ETH/BTC");
            CPPUNIT_ASSERT(output[0].orderType == OrderBookType::bid);
            CPPUNIT_ASSERT(output[0].price == 0.02187308);
            CPPUNIT_ASSERT(output[0].amount == 7.44564869);

        }



};