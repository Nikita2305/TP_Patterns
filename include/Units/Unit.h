class Unit;

#pragma once
#include "Units/UnitSquad.h"
#include "GameObjects/Player.h"
#include "Units/Positions/Position.h"
#include <memory>

class Unit {
public:
    virtual std::unique_ptr<Unit> copy() const = 0;
    virtual void act(Player& host, const Position& position) = 0;
    void getHurt(int attackValue);
    int getHealth() const;
protected:
    int healthValue;
};
