class Miner;

#pragma once
#include "Unit.h"

class Miner: public Unit {
public:
    virtual bool mine();
protected:
    int miningSpeed;
};