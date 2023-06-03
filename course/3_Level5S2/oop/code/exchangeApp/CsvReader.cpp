
#include "CsvReader.h"
#include "OrderBookEntry.h"
#include <fstream>

CsvReader::CsvReader(){};


OrderBookEntry CsvReader::stringsToOBE(std::vector<std::string> tokens) 
{
    
    double price;
    double amount;
    if (tokens.size() < 5) 
    {
        throw std::exception{};
    }
    try 
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception&e) 
    {
        throw e;
    }

    OrderBookEntry obe{price, amount, tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}

std::vector<std::string> CsvReader::tokenize(std::string csvLine, char separator) 
{
    std::vector<std::string> tokens;
    int start, end;
    start = csvLine.find_first_not_of(separator);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        std::string token;
        if (end >= 0) 
        {
            token = csvLine.substr(start, end - start);
        }
        else 
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    }
    while(end != std::string::npos);
    return tokens;
}

std::vector<OrderBookEntry> CsvReader::readCSV(std::string csvName) 
{
    
    std::vector<OrderBookEntry> result; 
    std::fstream csvFile{csvName};
    if (!csvFile.is_open()) 
    {
        std::cout << "CsvReader::readCSV - Failed to open" << std::endl;
    }
    else 
    {
        std::cout << "CsvReader::readCSV - Successful open" << std::endl;
        std::string line;
        int count = 0;
        while(std::getline(csvFile, line)) 
        {
            count ++;
            try 
            {
                std::vector<std::string> tokens = tokenize(line, ',');
                OrderBookEntry obe = stringsToOBE(tokens);
                result.push_back(obe);
            }
            catch(std::exception& e) 
            {   
                std::cout << "bad float at row number " << count << std::endl;
            }
        }
    }
    std::cout << "Number of successuly read lines " << result.size() << std::endl;
    csvFile.close();
    return result;
    
}



