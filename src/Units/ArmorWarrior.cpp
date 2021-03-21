#include "../../include/Units/ArmorWarrior.h"

ArmorWarrior::ArmorWarrior() {
    std::cout << "ArmorWarrior added" << std::endl;
    healthValue = 1000;
    attackValue = 1;
}

ArmorWarrior::~ArmorWarrior() {
    std::cout << "ArmorWarrior deleted" << std::endl;
}

Unit* ArmorWarrior::copy() {
    return new ArmorWarrior();
}