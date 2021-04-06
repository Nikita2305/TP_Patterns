#include "Units/ArmorWarrior.h"

ArmorWarrior::ArmorWarrior() {
    healthValue = 1000;
    attackValue = 1;
}

Unit* ArmorWarrior::copy() {
    return new ArmorWarrior();
}
