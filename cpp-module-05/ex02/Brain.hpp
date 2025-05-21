#ifndef _BRAIN_HPP__
#define _BRAIN_HPP__

#include <string>
#include <iostream>

class Brain {
private:
   std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain& obj);
    Brain& operator=(const Brain& obj);
};

#endif