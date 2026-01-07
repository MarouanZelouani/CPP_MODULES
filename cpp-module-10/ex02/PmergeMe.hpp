#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <climits>
#include <cctype>
#include <ctime>
#include <deque>
#include <iomanip>

struct Item {
    int value;
    Item* pair;

    Item(int value, Item* pair);
};

class PmergeMe {
private:
    std::vector<Item*> _data;
    std::vector<Item*> _sortedData;

    std::deque<Item*> _dataQ;
    std::deque<Item*> _sortedDataQ;

    double _durationForDeque;
    double _durationForVector;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& obj);
    PmergeMe& operator=(const PmergeMe& obj);

    void sort();
    void parseData(int ac, char **av);
    void displayResult() const;

    const std::vector<Item*>& getData() const;
    const std::vector<Item*>& getSortedData() const;

    bool isSorted() const;

private:
    int stringToInt(std::string& str) const;
    size_t jacobsthal(size_t n) const;

    // vector sorting methods 
    std::vector<Item*> fordJohnsonSort(std::vector<Item*> input);
    std::vector<size_t> generateInsertionOrder(size_t n);
    size_t binarySearchInsert(const std::vector<Item*>& vec, Item* Item, size_t start, size_t end) const;

    // deque sorting methods
    std::deque<Item*> fordJohnsonSortDeque(std::deque<Item*> input);
    std::deque<size_t> generateInsertionOrderDeque(size_t n);
    size_t binarySearchInsertDeque(const std::deque<Item*>& vec, Item* Item, size_t start, size_t end) const;
};