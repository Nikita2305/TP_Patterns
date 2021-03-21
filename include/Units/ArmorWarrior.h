class ArmorWarrior;

#pragma once
#include "Warrior.h"

class ArmorWarrior: public Warrior {
public:
    ArmorWarrior();
    ~ArmorWarrior() override;
    Unit* copy() override;
};