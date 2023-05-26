#ifndef CSVREADER_H
#define CSVREADER_H
#include <vector>
#include <iostream>
#include "OrderBookEntry.h"
#pragma once
    
class CsvReader
{
public:
    CsvReader();
    static std::vector<std::string> tokenize(std::string csvLine, char separator); 
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    static OrderBookEntry stringsToOBE(std::vector<std::string> row);

private:

};

#endif