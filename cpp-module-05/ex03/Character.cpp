#include "Character.hpp"

Character::Character() : name("default") {
    std::cout << "Character Default Constructor called" << std::endl;    
    for (int i = 0; i < 4; ++i)
        _materials[i] = NULL;
}

Character::Character(std::string name) : name(name) {
    std::cout << "Character Default Constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _materials[i] = NULL;
}

Character::~Character() {
    std::cout << "Character Deconstructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete _materials[i];
        _materials[i] = 0;
    }
}

Character::Character(const Character& obj) {
    std::cout << "Character Copy Constructor called" << std::endl;
    *this = obj;
}

Character& Character::operator=(const Character& obj) {
    if (this != &obj) {
        this->name = obj.name;
        for (int i = 0; i < 4; ++i) {
            delete _materials[i];
            _materials[i] = 0;
            if (obj._materials[i])
                _materials[i] = obj._materials[i]->clone();
            else 
                _materials[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    
    for (int i = 0; i < 4; i++) {
        if (!_materials[i]) {
            std::cout << "Materia has been added to the inventory!" << std::endl;
            _materials[i] = m;
            return ;
        }
    }
    std::cout << "Full inventory!" << std::endl;
}

void Character::unequip(int idx) {

    if (idx >= 0 && idx <= 4 && !_materials[idx]) {
        _materials[idx] = NULL;
        std::cout << "Materia has been removed for the inventory!" << std::endl; 
        return ;
    }
    std::cout << "No Materia with the Index of " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target) {

    if (idx >= 0 && idx <= 3 && _materials[idx]) {
        _materials[idx]->use(target);
        return ;
    }
    std::cout << "No Materia with the Index of " << idx << std::endl;
}