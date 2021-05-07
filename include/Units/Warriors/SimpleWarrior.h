#pragma once
#include "Warrior.h"

class SimpleWarrior: public Warrior {
public:
    SimpleWarrior();
    std::unique_ptr<Unit> copy() const override;
};
