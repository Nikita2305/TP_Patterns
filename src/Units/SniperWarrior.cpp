#include "../../include/Units/SniperWarrior.h"

SniperWarrior::SniperWarrior() {
    std::cout << "SniperWarrior added" << std::endl;
    healthValue = 1;
    attackValue = 1000;
}

SniperWarrior::~SniperWarrior() {
    std::cout << "SniperWarrior deleted" << std::endl;
}

Unit* SniperWarrior::copy() {
    return new SniperWarrior();
}