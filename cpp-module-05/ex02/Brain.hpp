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
    void setIdea(std::string idea);
    std::string getIdea(int idx) const;
};

#endif