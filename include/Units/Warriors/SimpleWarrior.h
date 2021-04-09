class SimpleWarrior;

#pragma once
#include "Warrior.h"

class SimpleWarrior: public Warrior {
public:
    SimpleWarrior();
    Unit* copy() override;
};
