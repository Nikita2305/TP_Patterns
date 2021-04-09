class ImmortalMiner;

#pragma once
#include "Miner.h"

class ImmortalMiner: public Miner {
public:
    ImmortalMiner();
    Unit* copy() override;
    bool mine() override;
};
