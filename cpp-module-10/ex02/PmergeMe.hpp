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

struct Pair {
    int value;
    size_t pair_idx;
};

class PmergeMe {
private:
    std::vector<int> _data;
    std::vector<int> _sortedData;

    // std::deque<int> _dataQ;
    // std::deque<int> _sortedDataQ;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& obj);
    PmergeMe& operator=(const PmergeMe& obj);

    void parseData(int ac, char **av);
    void sort();
    void displayBefore() const;
    void displayAfter() const;
    
    const std::vector<int>& getData() const;
    const std::vector<int>& getSortedData() const;

   bool isSorted() const;
private:
    std::vector<int> fordJohnsonSort(std::vector<int> inputVect);
    // std::deque<int> fordJohnsonSort(std::deque<int> inputVect);
    
    int stringToInt(std::string& str) const;
    size_t jacobsthal(size_t n) const;
    std::vector<size_t> generateInsertionOrder(size_t pendingSize);
    size_t binarySearchInsert(const std::vector<int>& vec, int value, size_t start, size_t end) const;
};