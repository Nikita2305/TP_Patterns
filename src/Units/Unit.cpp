#include "Units/Unit.h"

void Unit::getHurt(int attackValue) {
    healthValue -= attackValue;
}

int Unit::getHealth() const {
    return healthValue;
}