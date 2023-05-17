#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> tokenize(std::string csvLine, char separator) 
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

int main()
{
    // Testing the tokenize() function
    /*
    std::string testMe = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.0218,32.74659999";
    std::vector<std::string> results;
    results = tokenize(testMe, ',');
    for (std::string result: results) 
    {
        std::cout << result << std::endl; 
    }
    */

    // Opening the csv file
    std::fstream csvFile{"orderBook.csv"};
    if (!csvFile.is_open())
        std::cout << "failed to open" << std::endl;
    else 
    {
        // Reading the file
        std::cout << "Successful open" << std::endl;
        std::string line;
        while (std::getline(csvFile, line)) 
        {
            std::cout << "Read line " << line << std::endl;
        }
        csvFile.close();

    
    }

    
    return 0;
    
}


    
