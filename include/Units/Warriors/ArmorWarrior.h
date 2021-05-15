#pragma once
#include "Warrior.h"

class ArmorWarrior: public Warrior {
public:
    ArmorWarrior();
    std::unique_ptr<Unit> copy() const override;
};
