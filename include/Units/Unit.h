#pragma once
#include "Units/UnitSquad.h"

class Unit {
public:
    virtual std::unique_ptr<Unit> copy() const = 0;
    virtual void act(Player& host, const Position& position) = 0;
    void getHurt(int attackValue);
    int getHealth() const;
protected:
    int healthValue;
};
