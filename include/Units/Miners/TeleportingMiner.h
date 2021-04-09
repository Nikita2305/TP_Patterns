class TeleportingMiner;

#pragma once
#include "Miner.h"

class TeleportingMiner: public Miner {
public:
    TeleportingMiner();
    Unit* copy() override;
};
