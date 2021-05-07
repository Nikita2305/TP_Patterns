#include "Units/Warriors/SimpleWarrior.h"

SimpleWarrior::SimpleWarrior() {
    healthValue = 3;
    attackValue = 2;
}

std::unique_ptr<Unit> SimpleWarrior::copy() const {
    return std::make_unique<SimpleWarrior>();
}
