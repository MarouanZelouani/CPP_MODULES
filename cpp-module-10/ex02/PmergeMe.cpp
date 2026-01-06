#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) { *this = obj; }
PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
    if (this != &obj) {
        _data = obj._data;
        _sortedData = obj._sortedData;
    }
    return *this;
}

void PmergeMe::sort() {
    _sortedData = PmergeMe::fordJohnsonSort(_data);
}

const std::vector<int>& PmergeMe::getData() const {
    return _data;
}
const std::vector<int>& PmergeMe::getSortedData() const {
    return _sortedData;
}

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
            // if (!isValidPositiveInteger(token)) {
            //     throw std::runtime_error("Error: Invalid input: '" + token + "'");
            // }
    
            int value = stringToInt(token);
            
            _data.push_back(value);
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


std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> inputVect) {
    // handle base cases
    if (inputVect.size() == 0)
        return std::vector<int>();
    if (inputVect.size() == 1)
        return inputVect;
        
    // create pairs and compare
    std::vector<int> larger;
    std::vector<int> smaller;
    int straggler;
    bool hasStraggler = false;

    if (inputVect.size() % 2 != 0) {
        straggler = inputVect.back();
        inputVect.pop_back();
        hasStraggler = true;
    }

    for (size_t i = 0; i < inputVect.size(); i += 2) {
        int a = inputVect[i];
        int b = inputVect[i + 1];

        if (a > b) {
            larger.push_back(a);
            smaller.push_back(b);
        }
        else {
            larger.push_back(b);
            smaller.push_back(a);
        }
    }

    // recursively sort larger elements
    std::vector<int> mainChain = PmergeMe::fordJohnsonSort(larger);

    // insert first smaller element
    int firstSmall = smaller[0];
    mainChain.insert(mainChain.begin(), firstSmall);

    // build pending list with pair info
    std::vector<Pair> pending;
    for (size_t i = 1; i < smaller.size(); ++i) {
        Pair pair;
        pair.value = smaller[i];
        pair.pair_idx = i + 1;
        pending.push_back(pair);
    }

    if (hasStraggler) {
        Pair pair;
        pair.value = straggler;
        pair.pair_idx = mainChain.size();
        pending.push_back(pair);
    }

    // generate jacobsthal insertion order
    if (!pending.empty()) {
        std::vector<size_t> insertionOrder = generateInsertionOrder(pending.size());

        for (size_t i = 0; i < insertionOrder.size(); ++i) {
            size_t index = insertionOrder[i];
            int element = pending[index].value;
            size_t maxPos = pending[index].pair_idx;
            
            // binary search for insertion position
            size_t insertPos = binarySearchInsert(mainChain, element, 0, maxPos);
            
            // insert the element
            mainChain.insert(mainChain.begin() + insertPos, element);
            
            // update pair_idx for all remaining pending elements
            for (size_t j = 0; j < pending.size(); ++j) {
                if (pending[j].pair_idx >= insertPos) {
                    pending[j].pair_idx++;
                }
            }
        }
    }

    return mainChain;
}

size_t PmergeMe::jacobsthal(size_t n) const {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    // Iterative calculation: J(n) = J(n-1) + 2*J(n-2)
    size_t j0 = 0;
    size_t j1 = 1;
    
    for (size_t i = 2; i <= n; ++i) {
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    
    return j1;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendingSize) {
    std::vector<size_t> order;
    
    if (pendingSize == 0)
        return order;
    
    // special case: first element always goes first
    order.push_back(0);
    
    if (pendingSize == 1)
        return order;
    
    // generate jacobsthal numbers until we exceed pendingSize
    std::vector<size_t> jacobsthalNums;
    size_t k = 3; // start from J(3)
    
    while (true) {
        size_t jk = jacobsthal(k);
        if (jk >= pendingSize) {
            jacobsthalNums.push_back(pendingSize);
            break;
        }
        jacobsthalNums.push_back(jk);
        k++;
    }
    
    // build insertion order: within each range, insert in reverse
    size_t prevJacob = 1;
    
    for (size_t i = 0; i < jacobsthalNums.size(); ++i) {
        size_t jacob = jacobsthalNums[i];
        
        // insert from jacob down to prevJacob + 1 (in reverse)
        for (size_t pos = jacob; pos > prevJacob; --pos) {
            order.push_back(pos - 1); // convert to 0-indexed
        }
        
        prevJacob = jacob;
    }
    
    return order;
}

size_t PmergeMe::binarySearchInsert(const std::vector<int>& vec, int value, size_t start, size_t end) const {
    size_t left = start;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        
        if (vec[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

void PmergeMe::displayBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _data.size() && i < 5; ++i) {
        std::cout << _data[i] << " ";
    }
    if (_data.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _sortedData.size() && i < 5; ++i) {
        std::cout << _sortedData[i] << " ";
    }
    if (_sortedData.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

bool PmergeMe::isSorted() const {
    std::vector<int> vect = _sortedData;
    for (size_t i = 0; i < vect.size() - 1; ++i) {
        if (vect[i] > vect[i + 1]) return false;
    }
    return true;
}