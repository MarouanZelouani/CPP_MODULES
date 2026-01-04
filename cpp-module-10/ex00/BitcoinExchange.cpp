#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    csv_data_ = ParseFile("data.csv", ',', 0);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
    if (this != &obj) {
        csv_data_ = obj.csv_data_;
    }
    return *this;
}

Date BitcoinExchange::ParseDate(std::string string_date) const {
   Date date;
   char delimiter;
   
   std::stringstream ss(string_date);
   ss >> date.year >> delimiter >> date.month >> delimiter >> date.day;

   return date;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
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

// check the month (between 1 and 12)
// check Day
// - should be positive
// - determine day in the month
// - check for leap year is feb
// check year range (2000 - the actual year)
bool BitcoinExchange::isValideDate(Date date) const {
    if (date.month < 1 || date.month > 12 || date.day < 1 || date.day < 1)
        return false;

    time_t now = time(0);
    tm* current_time = localtime(&now);
    int current_year = current_time->tm_year + 1900;
    if (date.year > current_year || date.year < 2000)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(date.year)) days_in_month[1] = 29;
    
    if (date.day > days_in_month[date.month - 1])
        return false;

    return true;
}

std::map<Date, double> BitcoinExchange::ParseFile(std::string filename, char sep, int flag) const {
    std::ifstream file(filename.c_str());
    std::map<Date, double> container;
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return container;
    }
    
    std::string line;
    std::getline(file, line); // skip the first line

    while (std::getline(file, line)) {
        bool valid = true; 
        size_t pos = line.find(sep);
        
        if (pos == std::string::npos)
            std::cerr << "Error: invalid separator." << std::endl;

        std::string sub1 = line.substr(0, pos);
        std::string sub2 = line.substr(pos + 1);
        
        Date date = ParseDate(sub1);
        if (!isValideDate(date)) {
            std::cerr << "Error: bad input => " << sub1 << std::endl;
            valid = false;
        }
        
        std::stringstream ss(sub2);
        double value;
        ss >> value;

        if (ss.fail()) {
            std::cerr << "Error: bad input => " << std::endl;
            valid = false;
        } else if (value < 0 && flag == 1) {
            std::cerr << "Error: not a positive number." << std::endl;
            valid = false;
        }
        else if (value > 1000 && flag == 1) {
            std::cerr << "Error: too large a number." << std::endl; 
            valid = false;
            std::cout << "dsdsd=> " << value << sub2 << "\n";
        }
        
        if (flag == 0 && !valid) {
            file.close();
            throw std::runtime_error("Error: csv parsing problem!");
        } 
        
        if (flag == 1 && valid)
            exchange(date, value);
        else 
            container[date] = value;

        valid = true;
    }

    file.close();
    return container;
}

void BitcoinExchange::exchange(Date date, double value) const {
    double exchange_rate;
    std::map<Date, double>::const_iterator it_upper = csv_data_.upper_bound(date);

    if (it_upper != csv_data_.begin()) {
        --it_upper;
        exchange_rate = it_upper->second;
        std::cout << date << " => " << value  << " = " << value * exchange_rate << std::endl; 
    } else 
        std::cout << "No data availble for date: " << date << " \n";
}


void BitcoinExchange::exchange(std::string filename) const {
    (void)ParseFile(filename, '|', 1);
}