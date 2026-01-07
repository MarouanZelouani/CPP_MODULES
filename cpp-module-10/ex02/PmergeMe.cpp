#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

Item::Item(int value, Item* pair) : value(value), pair(pair) {}

PmergeMe::~PmergeMe() {
    if (!_data.empty()) {
        for (size_t i = 0; i < _data.size(); ++i) {
            delete _data[i];
            delete _dataQ[i];
        }
    }
    _data.clear();
    _sortedData.clear();
}

PmergeMe::PmergeMe(const PmergeMe& obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
    if (this != &obj) {
        _data = obj._data;
        _sortedData = obj._sortedData;
    }
    return *this;
}

// ===================== helper functions =========================

void PmergeMe::sort() {
    std::clock_t start = std::clock();

    _sortedData = PmergeMe::fordJohnsonSort(_data);
    _durationForVector = double(std::clock() - start) * 1e6 / CLOCKS_PER_SEC;

    start = std::clock();
    _sortedDataQ = PmergeMe::fordJohnsonSortDeque(_dataQ);
    _durationForDeque = double(std::clock() - start) * 1e6 / CLOCKS_PER_SEC;
}

size_t PmergeMe::jacobsthal(size_t n) const {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    // J(n) = J(n-1) + 2*J(n-2)
    size_t j0 = 0;
    size_t j1 = 1;
    
    for (size_t i = 2; i <= n; ++i) {
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    
    return j1;
}

bool PmergeMe::isSorted() const {
    std::deque<Item*> vect = _sortedDataQ;
    for (size_t i = 0; i < vect.size() - 1; ++i) {
        if (vect[i]->value > vect[i + 1]->value) return false;
    }
    return true;
}

// ========================= Parsing ================================

void PmergeMe::parseData(int ac, char **av) {
    if (ac < 2)
        throw std::runtime_error("Error: No input provided");
    
    for (int i = 1; i < ac; ++i) {
        std::string arg(av[i]);
        
        if (arg.empty())
            continue;
        
        std::stringstream ss(arg);
        std::string token;
        
        while (ss >> token) {
            
            // add this 
            // if (!isValidPositiveInteger(token)) {
            //     throw std::runtime_error("Error: Invalid input: '" + token + "'");
            // }
    
            int value = stringToInt(token);
            
            Item* item = new Item(value, NULL);
            Item* itemQ = new Item(value, NULL);
            _data.push_back(item);
            _dataQ.push_back(itemQ);
        }
    }
    if (_data.empty())
        throw std::runtime_error("Error: No input provided");
}

int PmergeMe::stringToInt(std::string& str) const {
    if (!str.empty() && str[0] == '+')
        str = str.substr(1);
    
    std::stringstream ss(str);
    long long value;
    ss >> value;
    
    // check for overflow
    if (value > INT_MAX || value < 0) {
        throw std::runtime_error("Error: Number out of range: " + str);
    }

    return static_cast<int>(value);
}

// ========================= SORTING FOR VECTOR ================================

std::vector<Item*> PmergeMe::fordJohnsonSort(std::vector<Item*> input) {
    
    if (input.size() == 0)
        return std::vector<Item*>();
    if (input.size() == 1)
        return input;

    std::vector<Item *> larger;
    std::vector<Item *> smaller;
    Item* straggler = NULL;

    if (input.size() % 2 != 0) {
        straggler = input.back();
        input.pop_back();
    }

    for (size_t i = 0; i < input.size(); i += 2) {
        Item* a = input[i];
        Item* b = input[i + 1];

        if (a->value > b->value) {
            larger.push_back(a);
            smaller.push_back(b);

            if (b->pair == NULL)
                b->pair = a;
        } else {
            larger.push_back(b);
            smaller.push_back(a);

            if (a->pair == NULL)
                a->pair = b;
        }
    }

    std::vector<Item*> mainChain = PmergeMe::fordJohnsonSort(larger);
    std::vector<Item*> pending = smaller;

    std::vector<size_t> order = generateInsertionOrder(pending.size());
    for (size_t i = 0; i < order.size(); ++i) {
        Item* b = pending[order[i]];
        Item* a = b->pair;

        size_t rightBound = mainChain.size();
        if (a) {
            for (size_t j = 0; j < mainChain.size(); ++j) {
                if (mainChain[j] == a) {
                    rightBound = j;
                    break;
                }
            }
        }

        size_t pos = binarySearchInsert(mainChain, b, 0, rightBound);
        mainChain.insert(mainChain.begin() + pos, b);
    }

    if (straggler) {
        size_t pos = binarySearchInsert(mainChain, straggler, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }

    return mainChain;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n <= 1)
        return order;

    size_t prev = 1;
    size_t k = 3;

    while (true) {
        size_t j = jacobsthal(k);
        if (j >= n)
            break;

        for (size_t i = j; i > prev; --i)
            order.push_back(i - 1);

        prev = j;
        ++k;
    }

    for (size_t i = n; i > prev; --i)
        order.push_back(i - 1);

    return order;
}

size_t PmergeMe::binarySearchInsert(const std::vector<Item*>& vec, Item* item, size_t start, size_t end) const {
    size_t left = start;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        
        if (vec[mid]->value < item->value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// ========================= SORTING FOR DEQUE =============================

std::deque<Item*> PmergeMe::fordJohnsonSortDeque(std::deque<Item*> input) {
    
    if (input.size() == 0)
        return std::deque<Item*>();
    if (input.size() == 1)
        return input;

    std::deque<Item *> larger;
    std::deque<Item *> smaller;
    Item* straggler = NULL;

    if (input.size() % 2 != 0) {
        straggler = input.back();
        input.pop_back();
    }

    for (size_t i = 0; i < input.size(); i += 2) {
        Item* a = input[i];
        Item* b = input[i + 1];

        if (a->value > b->value) {
            larger.push_back(a);
            smaller.push_back(b);

            if (b->pair == NULL)
                b->pair = a;
        } else {
            larger.push_back(b);
            smaller.push_back(a);

            if (a->pair == NULL)
                a->pair = b;
        }

    }

    std::deque<Item*> mainChain = PmergeMe::fordJohnsonSortDeque(larger);
    std::deque<Item*> pending = smaller;

    std::deque<size_t> order = generateInsertionOrderDeque(pending.size());
    for (size_t i = 0; i < order.size(); ++i) {
        Item* b = pending[order[i]];
        Item* a = b->pair;

        size_t rightBound = mainChain.size();
        if (a) {
            for (size_t j = 0; j < mainChain.size(); ++j) {
                if (mainChain[j] == a) {
                    rightBound = j;
                    break;
                }
            }
        }

        size_t pos = binarySearchInsertDeque(mainChain, b, 0, rightBound);
        mainChain.insert(mainChain.begin() + pos, b);
    }

    if (straggler) {
        size_t pos = binarySearchInsertDeque(mainChain, straggler, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }

    return mainChain;
}

std::deque<size_t> PmergeMe::generateInsertionOrderDeque(size_t n) {
    std::deque<size_t> order;
    if (n <= 1)
        return order;

    size_t prev = 1;
    size_t k = 3;

    while (true) {
        size_t j = jacobsthal(k);
        if (j >= n)
            break;

        for (size_t i = j; i > prev; --i)
            order.push_back(i - 1);

        prev = j;
        ++k;
    }

    for (size_t i = n; i > prev; --i)
        order.push_back(i - 1);

    return order;
}

size_t PmergeMe::binarySearchInsertDeque(const std::deque<Item*>& vec, Item* item, size_t start, size_t end) const {
    size_t left = start;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        
        if (vec[mid]->value < item->value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// ========================= DISPLAYING ================================

void PmergeMe::displayResult() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _data.size() && i < 5; ++i) {
        std::cout << _data[i]->value << " ";
    }
    if (_data.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    std::cout << "After:  ";
    for (size_t i = 0; i < _sortedData.size() && i < 5; ++i) {
        std::cout << _sortedData[i]->value << " ";
    }
    if (_sortedData.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " <<  _data.size();
    std::cout <<  " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(2) << _durationForVector;
    std::cout << " us" << std::endl;
    std::cout << "Time to process a range of " <<  _dataQ.size();
    std::cout <<  " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(2) << _durationForDeque;
    std::cout << " us" << std::endl;
}

