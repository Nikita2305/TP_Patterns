#include "Units/Miners/SimpleMiner.h"

SimpleMiner::SimpleMiner() {
    healthValue = 5;
    miningSpeed = 2;
}

std::unique_ptr<Unit> SimpleMiner::copy() const {
    return std::make_unique<SimpleMiner>();
}