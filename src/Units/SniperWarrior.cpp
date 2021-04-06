#include "Units/SniperWarrior.h"

SniperWarrior::SniperWarrior() {
    healthValue = 1;
    attackValue = 1000;
}

Unit* SniperWarrior::copy() {
    return new SniperWarrior();
}
