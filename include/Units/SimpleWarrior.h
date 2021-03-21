class SimpleWarrior;

#pragma once
#include "Warrior.h"

class SimpleWarrior: public Warrior {
public:
    SimpleWarrior();
    ~SimpleWarrior() override;
    Unit* copy() override;
};