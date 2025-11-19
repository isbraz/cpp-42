#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));
    
    int year, month, day;
    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    if (valueStr.empty())
        return false;

    for (size_t i = 0; i < valueStr.length(); ++i)
    {
        if (valueStr[i] != '-' && valueStr[i] != '+' && valueStr[i] != '.' && 
            (valueStr[i] < '0' || valueStr[i] > '9'))
            return false;
    }

    if (valueStr == "-" || valueStr == "+" || valueStr == ".")
        return false;

    std::istringstream iss(valueStr);
    iss >> value;

    if (iss.fail() || !iss.eof())
        return false;

    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));

        double rate;
        if (isValidDate(date) && isValidValue(rateStr, rate))
            _exchangeRates[date] = rate;
    }

    file.close();
    return !_exchangeRates.empty();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end())
        return it->second;

    it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin())
        return 0.0;

    --it;
    return it->second;
}

bool BitcoinExchange::initialize(const std::string& databaseFile)
{
    return loadDatabase(databaseFile);
}

void BitcoinExchange::processInputFile(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (valueStr.empty())
        {
            std::cerr << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }

        if (value < 0 || (value == 0 && valueStr[0] == '-'))
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = getExchangeRate(date);
        double result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}
