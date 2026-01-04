#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

struct Date {
    int day;
    int month;
    int year;

    bool operator<(const Date& other) const;
};

class BitcoinExchange {
private:
    std::map<Date, double> csv_data_;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);

    void exchange(std::string filename) const;
    void exchange(Date date, double value) const;

private:
    // Helper methods
    std::map<Date, double> ParseFile(std::string filename, char sep, int flag) const;
    Date ParseDate(std::string string_date) const;
    bool isValideDate(Date date) const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);