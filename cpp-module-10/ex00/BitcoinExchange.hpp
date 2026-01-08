#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

struct Date {
    int day;
    int month;
    int year;

    bool operator<(const Date& other) const;
};

class BitcoinExchange {
private:
    std::map<Date, double> _database;
    int _currentYear;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);

    void processInput(const std::string& filename);
    
private:
    void loadDatabase(const std::string& filename);
    
    // parsing
    bool parseLine(const std::string& line, char separator, 
        std::string& datestr, std::string& valuestr);
    bool parseDate(const std::string& datestr, Date& date);
    bool parseValue(const std::string& valuestr, double& value);
    
    double getExchangeRate(const Date& date) const;
    void displayExchange(const Date& date, double value) const;
    
    bool isValidDate(Date date) const;
    std::string trim(const std::string& str) const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);