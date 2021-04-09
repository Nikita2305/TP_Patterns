class Miner;

#pragma once
#include "Unit.h"

class Miner: public Unit {
public:
    void act() override;
    virtual void mine();
protected:
    int miningSpeed;
};