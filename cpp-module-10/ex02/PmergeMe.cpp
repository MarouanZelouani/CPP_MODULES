#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& obj){}
PmergeMe& PmergeMe::operator=(const PmergeMe& obj){}

void PmergeMe::parseData(int ac, char **av) {
    if (ac < 2) {
        throw std::runtime_error("Error: No input provided");
    }
    
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
}

int PmergeMe::stringToInt(std::string str) const {
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
    }

    for (int i = 0; i < inputVect.size(); ++i) {
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
    mainChain.insert(mainChain.begin(), 1);

    // build pending list with pair info
    std::vector<Pair> pending;
    for (int i = 1; i < smaller.size(); ++i) {
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
    std::vector<int> insertionOrder = generateInsertionOrder(pending.size());

    // insert pending elements
    for (int i = 0; i < insertionOrder.size(); ++i) {
        
    }
}