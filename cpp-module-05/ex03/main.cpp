#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    tmp = src->createMateria("test");
    me->equip(tmp);  

    ICharacter* bob = new Character("bob");
    
    std::cout << "\n";
    
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    
    me->unequip(2);
    me->unequip(1);
    
    
    std::cout << "\n";
    
    delete bob;
    delete me;
    delete src;
    
    return 0;
}