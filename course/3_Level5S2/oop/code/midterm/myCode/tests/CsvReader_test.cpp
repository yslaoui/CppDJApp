// cpp unit includes
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


// app specific includes


#include "../CSVReader.h"
#include "../OrderBookEntry.h"
#include <fstream>

class CsvReaderTest : public CppUnit::TestFixture 
{
    public: 
        void test_tokenize() 
        {
            std::string csvLine = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
            std::vector<std::string> result = CSVReader::tokenize(csvLine, ',');
            CPPUNIT_ASSERT(result[0] == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(result[1] == "ETH/BTC");
            CPPUNIT_ASSERT(result[2] == "bid");
            CPPUNIT_ASSERT(result[3] == "0.02187308");
            CPPUNIT_ASSERT(result[4] == "7.44564869");    
        }

        void test_stringsToOBE() 
        {
            std::string csvLine = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
            std::vector<std::string> input = CSVReader::tokenize(csvLine, ',');
            OrderBookEntry output = CSVReader::stringsToOBE(input);
            CPPUNIT_ASSERT(output.timestamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(output.product == "ETH/BTC");
            CPPUNIT_ASSERT(output.orderType == OrderBookType::bid);
            CPPUNIT_ASSERT(output.price == 0.02187308);
            CPPUNIT_ASSERT(output.amount == 7.44564869);
        }

        void test_readCSV() 
        {
            std::string input = "../orderBook.csv";
            std::vector<OrderBookEntry> output = CSVReader::readCSV(input);
            CPPUNIT_ASSERT(output[0].timestamp == "2020/03/17 17:01:24.884492");
            CPPUNIT_ASSERT(output[0].product == "ETH/BTC");
            CPPUNIT_ASSERT(output[0].orderType == OrderBookType::bid);
            CPPUNIT_ASSERT(output[0].price == 0.02187308);
            CPPUNIT_ASSERT(output[0].amount == 7.44564869);

        }

        void test_stringsToOBEStrings() 
        {
            std::string price = "0.02186299";
            std::string amount = "0.1";
            std::string timeStamp = "2020/03/17 17:01:24.884492";
            std::string product = "ETH/BTC";            
            OrderBookType type = OrderBookType::ask;
            OrderBookEntry result = CSVReader::stringsToOBE(price, amount, timeStamp, product, type);
            CPPUNIT_ASSERT(result.price == 0.02186299);
            CPPUNIT_ASSERT(result.amount == 0.1);
            CPPUNIT_ASSERT(result.timestamp == timeStamp);
            CPPUNIT_ASSERT(result.product == product);
            CPPUNIT_ASSERT(result.orderType == type);
        }
};