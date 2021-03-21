class Warrior;

#pragma once
#include "Unit.h"

class Warrior: public Unit {
public:
    virtual void attack();
protected:
    int attackValue;
};