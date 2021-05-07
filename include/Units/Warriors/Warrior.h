#pragma once
#include "Units/Unit.h"

class Warrior: public Unit {
public:
    void act(Player& host, const Position& position) override;
    virtual void attack(const Position& position) const;
protected:
    int attackValue;
};