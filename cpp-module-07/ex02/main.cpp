#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int choice = std::rand() % 3;
    Base* obj = 0;
    if (choice == 0)
        obj = new A();
    else if (choice == 1)
        obj = new B();
    else
        obj = new C();
    return obj;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A!" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C!" << std::endl;
    else 
        std::cout << "Unknown Type!" << std::endl;
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A!" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B!" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C!" << std::endl;
    else 
        std::cout << "Unknown Type!" << std::endl;
}


int main (void) {

    int run = 20;
    for (int i = 0; i < run; i++) {
        Base* tmp = generate();
        identify(tmp);
        identify(*tmp);    
    }
    return 0;
}