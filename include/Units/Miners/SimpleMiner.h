#pragma once
#include "Units/Miners/Miner.h"

class SimpleMiner: public Miner {
public:
    SimpleMiner();
    std::unique_ptr<Unit> copy() const override;
};
