// BitcoinExchange.hpp
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <limits>

struct Date {
    int year;
    int month;
    int day;

    Date() : year(0), month(0), day(0) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    bool operator<(const Date& other) const;
};

class BitcoinExchange {
private:
    std::map<Date, double> database_;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);

    void processInputFile(const std::string& filename);

private:
    // Parsing methods
    void loadDatabase(const std::string& filename);
    bool parseLine(const std::string& line, char separator, 
                   std::string& dateStr, std::string& valueStr);
    bool parseDate(const std::string& dateStr, Date& date);
    bool parseValue(const std::string& valueStr, double& value);
    
    // Validation methods
    bool isValidDate(const Date& date) const;
    bool isLeapYear(int year) const;
    
    // Utility methods
    std::string trim(const std::string& str) const;
    double getExchangeRate(const Date& date) const;
    void displayExchange(const Date& date, double value) const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

// ============================================================================
// BitcoinExchange.cpp

#include "BitcoinExchange.hpp"

// Date implementation
bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.year << "-";
    if (date.month < 10) os << "0";
    os << date.month << "-";
    if (date.day < 10) os << "0";
    os << date.day;
    return os;
}

// BitcoinExchange implementation
BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
    if (this != &obj) {
        database_ = obj.database_;
    }
    return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    // Find first non-whitespace
    while (start < end && std::isspace(str[start])) {
        ++start;
    }
    
    // Find last non-whitespace
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    
    return str.substr(start, end - start);
}

bool BitcoinExchange::parseLine(const std::string& line, char separator,
                                 std::string& dateStr, std::string& valueStr) {
    size_t pos = line.find(separator);
    
    if (pos == std::string::npos) {
        return false;
    }
    
    dateStr = trim(line.substr(0, pos));
    valueStr = trim(line.substr(pos + 1));
    
    return !dateStr.empty() && !valueStr.empty();
}

bool BitcoinExchange::parseDate(const std::string& dateStr, Date& date) {
    std::stringstream ss(dateStr);
    char delimiter1, delimiter2;
    
    ss >> date.year >> delimiter1 >> date.month >> delimiter2 >> date.day;
    
    // Check if parsing succeeded and format is correct
    if (ss.fail() || !ss.eof() || delimiter1 != '-' || delimiter2 != '-') {
        return false;
    }
    
    return isValidDate(date);
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& value) {
    std::stringstream ss(valueStr);
    ss >> value;
    
    // Check if parsing succeeded and there's no trailing characters
    if (ss.fail()) {
        return false;
    }
    
    // Check for trailing non-whitespace characters
    std::string remaining;
    ss >> remaining;
    if (!remaining.empty()) {
        return false;
    }
    
    return true;
}

bool BitcoinExchange::isLeapYear(int year) const {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return year % 400 == 0;
}

bool BitcoinExchange::isValidDate(const Date& date) const {
    // Check year range
    if (date.year < 2009 || date.year > 2024) {
        return false;
    }
    
    // Check month range
    if (date.month < 1 || date.month > 12) {
        return false;
    }
    
    // Check day range
    if (date.day < 1) {
        return false;
    }
    
    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Adjust February for leap years
    if (isLeapYear(date.year)) {
        daysInMonth[1] = 29;
    }
    
    if (date.day > daysInMonth[date.month - 1]) {
        return false;
    }
    
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        std::string dateStr, valueStr;
        
        if (!parseLine(line, ',', dateStr, valueStr)) {
            file.close();
            throw std::runtime_error("Error: invalid database format.");
        }
        
        Date date;
        if (!parseDate(dateStr, date)) {
            file.close();
            throw std::runtime_error("Error: invalid date in database.");
        }
        
        double value;
        if (!parseValue(valueStr, value)) {
            file.close();
            throw std::runtime_error("Error: invalid value in database.");
        }
        
        database_[date] = value;
    }
    
    file.close();
    
    if (database_.empty()) {
        throw std::runtime_error("Error: empty database.");
    }
}

double BitcoinExchange::getExchangeRate(const Date& date) const {
    std::map<Date, double>::const_iterator it = database_.upper_bound(date);
    
    if (it == database_.begin()) {
        return -1; // No data available for this date
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

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        std::string dateStr, valueStr;
        
        // Parse line
        if (!parseLine(line, '|', dateStr, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Parse date
        Date date;
        if (!parseDate(dateStr, date)) {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        // Parse value
        double value;
        if (!parseValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        // Validate value range
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Display result
        displayExchange(date, value);
    }
    
    file.close();
}

// ============================================================================
// main.cpp

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        exchange.processInputFile(av[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}