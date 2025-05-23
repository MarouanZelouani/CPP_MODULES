#ifndef _CHARACTER_HPP__
#define _CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MATERIA_SIZE 500

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* _materials[4];
    int _collector_size;
    AMateria* _collector[MATERIA_SIZE];
public:
    Character();
    Character(std::string name);
    ~Character();
    Character(const Character& obj);
    Character& operator=(const Character& obj);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif