#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <climits>

struct Pair {
    int value;
    size_t pair_idx;
};

class PmergeMe {
private:
    std::vector<int> _data;
    std::vector<int> _sortedDate;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& obj);
    PmergeMe& operator=(const PmergeMe& obj);

    void parseData(int ac, char **av);
    int stringToInt(std::string str) const;
    void sort();

private:
    std::vector<int> fordJohnsonSort(std::vector<int> inputVect);
    std::vector<int> generateInsertionOrder(size_t pendingSize);
};