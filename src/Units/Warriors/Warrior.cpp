#include "Units/Warriors/Warrior.h"

void Warrior::act() {
    attack();
}

void Warrior::attack() {
    position->next(1)->extractUnitEntity()->getHurt(attackValue);
}
