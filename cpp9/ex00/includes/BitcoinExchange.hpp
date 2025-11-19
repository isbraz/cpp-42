#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, double> _exchangeRates;

    bool loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, double& value) const;
    std::string trim(const std::string& str) const;
    double getExchangeRate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool initialize(const std::string& databaseFile);
    void processInputFile(const std::string& inputFile);
};