class Warrior;

#pragma once
#include "Unit.h"

class Warrior: public Unit {
public:
    void act() override;
    virtual void attack();
protected:
    int attackValue;
};