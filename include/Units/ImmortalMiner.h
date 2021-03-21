class ImmortalMiner;

#pragma once
#include "Miner.h"

class ImmortalMiner: public Miner {
public:
    ImmortalMiner();
    ~ImmortalMiner() override;
    Unit* copy() override;
    bool mine() override;
};