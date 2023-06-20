#include "Wallet.h"
#include "CsvReader.h"

Wallet::Wallet() {};

void Wallet::insertCurrency(std::string currency, double amount) 
{
    int balance; 
    wallet.count(currency) ? (balance = 0) :  (balance = wallet[currency]);
    balance += amount;
    wallet[currency] = balance; 
}

bool Wallet::containsCurrency(std::string currency, double amount)
{
    if (!wallet.count(currency)) 
    {
        return false;
    }
    else 
    {
        return (wallet[currency] >= amount);
    }
}

std::string Wallet::toString() 
{
    std::string result;
    for (std::pair<std::string, double> e: wallet) 
    {
        result += e.first + " " + std::to_string(e.second) + '\n';
    }
    return result;
}


bool Wallet::removeCurrency(std::string currency, double amount) 
{
    if (amount < 0) 
    {
        std::cout << "Wallet::removeCurrency: amount entered should be positive" << std::endl;
        return false;
    } 
    if (!wallet.count(currency)) 
    {
        std::cout << "Wallet::removeCurrency: Wallet does not contain currency" << std::endl;
        return false;
    }  
    else if (wallet[currency] >= amount) 
    {
        std::cout << "Wallet::removeCurrency: Currency successfully decreased by amount" << std::endl;
        wallet[currency] -= amount;
        return true;
    }
    else 
    {
        std::cout << "Wallet::removeCurrency: Currency found by funds are insufficient" << std::endl; 
        return false;
    }
}

bool Wallet::canFulfillOrder(OrderBookEntry order) 
{
    std::string currency;
    double amount;
    if (order.orderType == OrderBookType::ask) 
    {

        currency = CsvReader::tokenize(order.product, '/')[0];
        amount = order.amount;
        std::cout << "order is an ask, currency:  " << currency << " amount " << amount <<  std::endl;
    }
    if (order.orderType == OrderBookType::bid) 
    {
        currency = CsvReader::tokenize(order.product, '/')[1];
        amount = order.amount * order.price;
        std::cout << "order is a bid, currency:  " << currency << " amount " << amount <<  std::endl;      
    }
    return containsCurrency(currency, amount);  
}

void Wallet::processSale(OrderBookEntry& sale) 
{
    std::string currency;
    double amount;
    std::string outgoingCurrency;
    std::string incomingCurrency;

    if (sale.orderType == OrderBookType::asksale) 
    {
        outgoingCurrency = CsvReader::tokenize(sale.product, '/')[0];
        incomingCurrency = CsvReader::tokenize(sale.product, '/')[1];
        std::cout << "outgoingCurrency " <<  outgoingCurrency << std::endl;
        std::cout << "incomingCurrency " <<  incomingCurrency << std::endl;
        wallet[outgoingCurrency] -= sale.amount;
        wallet[incomingCurrency] += sale.price * sale.amount;
    }
    if (sale.orderType == OrderBookType::bidsale) 
    {
        outgoingCurrency = CsvReader::tokenize(sale.product, '/')[1];
        incomingCurrency = CsvReader::tokenize(sale.product, '/')[0];
        std::cout << "outgoingCurrency " <<  outgoingCurrency << std::endl;
        std::cout << "incomingCurrency " <<  incomingCurrency << std::endl;
        wallet[outgoingCurrency] -= sale.price * sale.amount;
        wallet[incomingCurrency] += sale.amount;   
     }
}






























