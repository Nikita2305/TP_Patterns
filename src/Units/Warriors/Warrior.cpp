#include "Units/Warriors/Warrior.h"

void Warrior::act(Player& host, const Position& position) {
    attack(position);
}

void Warrior::attack(const Position& position) const {
    std::unique_ptr<Position> target_position = position.next();
    if (target_position->containsUnitSquad()) {
        target_position->extractUnitSquad()->getHurt(attackValue);
    }
}
