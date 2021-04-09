class SimpleMiner;

#pragma once
#include "Miner.h"

class SimpleMiner: public Miner {
public:
    SimpleMiner();
    Unit* copy() override;
};
