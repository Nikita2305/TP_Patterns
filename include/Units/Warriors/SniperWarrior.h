#pragma once
#include "Warrior.h"

class SniperWarrior: public Warrior {
public:
    SniperWarrior();
    std::unique_ptr<Unit> copy() const override;
    void attack(const Position& position) const override;
};
