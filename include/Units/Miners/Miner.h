#pragma once
#include "Units/Unit.h"

class Miner: public Unit {
public:
    void act(Player& host, const Position& position) override;
    virtual void mine(Player& host);
protected:
    int miningSpeed;
};