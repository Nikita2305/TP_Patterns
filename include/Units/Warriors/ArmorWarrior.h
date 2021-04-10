class ArmorWarrior;

#pragma once
#include "Warrior.h"

class ArmorWarrior: public Warrior {
public:
    ArmorWarrior();
    Unit* copy() override;
};
