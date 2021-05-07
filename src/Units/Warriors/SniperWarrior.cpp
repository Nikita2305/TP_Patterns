#include "Units/Warriors/SniperWarrior.h"

SniperWarrior::SniperWarrior() {
    healthValue = 1;
    attackValue = 3;
}

std::unique_ptr<Unit> SniperWarrior::copy() const {
    return std::make_unique<SniperWarrior>();
}

void SniperWarrior::attack(const Position& position) const {
    std::unique_ptr<Position> target_position = position.next()->next();
    if (target_position->containsUnitSquad()) {
        target_position->extractUnitSquad()->getHurt(attackValue);
    }
}
