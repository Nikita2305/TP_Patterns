#include "Units/Warriors/ArmorWarrior.h"

ArmorWarrior::ArmorWarrior() {
    healthValue = 10;
    attackValue = 1;
}

std::unique_ptr<Unit> ArmorWarrior::copy() const {
    return std::make_unique<ArmorWarrior>();
}
