class TeleportingMiner;

#pragma once
#include "Miner.h"

class TeleportingMiner: public Miner {
public:
    TeleportingMiner();
    ~TeleportingMiner() override;
    Unit* copy() override;
};