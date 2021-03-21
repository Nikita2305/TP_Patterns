class Unit;

#pragma once
#include <iostream>

class Unit{
public:
    virtual Unit* copy() = 0;
    virtual ~Unit() = default;
protected:
    int healthValue;
};
