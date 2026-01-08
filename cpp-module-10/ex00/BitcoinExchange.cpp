#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    time_t now = time(0);
    tm* current_time = localtime(&now);
    _currentYear = current_time->tm_year + 1900;
    loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
    if (this != &obj) {
        _database = obj._database;
        _currentYear = obj._currentYear;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.year << "-";
    if (date.month < 10) os << "0";
    os << date.month << "-";
    if (date.day < 10) os << "0";
    os << date.day;
    return os;
}


bool BitcoinExchange::parseLine(const std::string& line, char separator, std::string& datestr, std::string& valuestr) {
    size_t pos = line.find(separator);

    if (pos == std::string::npos)
        return false;

    datestr = trim(line.substr(0, pos));
    valuestr = trim(line.substr(pos + 1));

    return !datestr.empty() && !valuestr.empty();
}

bool BitcoinExchange::parseDate(const std::string& datestr, Date& date) {
    std::stringstream ss(datestr);
    char delimiter1, delimiter2;

    ss >> date.year >> delimiter1 >> date.month >> delimiter2 >> date.day;

    if (ss.fail() || !ss.eof() || delimiter1 != '-' || delimiter2 != '-')
        return false;

    return isValidDate(date);
}

bool BitcoinExchange::parseValue(const std::string& valuestr, double& value) {
    std::stringstream ss(valuestr);
    ss >> value;

    if (ss.fail())
        return false;
    
    std::string remaining;
    ss >> remaining;
    if (!remaining.empty())
        return false;
    
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::string dateStr, valueStr;
        
        if (!parseLine(line, ',', dateStr, valueStr)) {
            file.close();
            throw std::runtime_error("Error: invalid database format!");
        }
        
        Date date;
        if (!parseDate(dateStr, date)) {
            file.close();
            throw std::runtime_error("Error: invalid date in database!");
        }
        
        double value;
        if (!parseValue(valueStr, value)) {
            file.close();
            throw std::runtime_error("Error: invalid value in database!");
        }
        
        _database[date] = value;
    }
    
    file.close();
    
    if (_database.empty()) {
        throw std::runtime_error("Error: empty database!");
    }
}



bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool BitcoinExchange::isValidDate(Date date) const {
    if (date.month < 1 || date.month > 12 || date.day < 1)
        return false;

    if (date.year > _currentYear || date.year < 2009)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(date.year)) days_in_month[1] = 29;
    
    if (date.day > days_in_month[date.month - 1])
        return false;

    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file!" << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::string dateStr, valueStr;
        
        if (!parseLine(line, '|', dateStr, valueStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        Date date;
        if (!parseDate(dateStr, date)) {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        double value;
        if (!parseValue(valueStr, value)) {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        displayExchange(date, value);
    }
    
    file.close();
}

double BitcoinExchange::getExchangeRate(const Date& date) const {
    std::map<Date, double>::const_iterator it = _database.upper_bound(date);
    
    if (it == _database.begin()) {
        return -1;
    }
    
    --it;
    return it->second;
}


void BitcoinExchange::displayExchange(const Date& date, double value) const {
    double rate = getExchangeRate(date);
    
    if (rate < 0) {
        std::cout << "Error: no data available for date => " << date << std::endl;
        return;
    }
    
    std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && std::isspace(str[start])) {
        ++start;
    }
    
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    
    return str.substr(start, end - start);
}