#pragma once
#include "Units/Miners/Miner.h"

class ImmortalMiner: public Miner {
public:
    ImmortalMiner();
    std::unique_ptr<Unit> copy() const override;
    void mine(Player&) override;
};
