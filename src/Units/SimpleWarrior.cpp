#include "../../include/Units/SimpleWarrior.h"

SimpleWarrior::SimpleWarrior() {
    std::cout << "SimpleWarrior added" << std::endl;
    healthValue = 5;
    attackValue = 6;
}

SimpleWarrior::~SimpleWarrior() {
    std::cout << "SimpleWarrior deleted" << std::endl;
}

Unit* SimpleWarrior::copy() {
    return new SimpleWarrior();
}
