class SniperWarrior;

#pragma once
#include "Warrior.h"

class SniperWarrior: public Warrior {
public:
    SniperWarrior();
    Unit* copy() override;
};
