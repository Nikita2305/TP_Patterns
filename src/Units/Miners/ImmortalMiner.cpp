#include "Units/Miners/ImmortalMiner.h"

ImmortalMiner::ImmortalMiner() {
    healthValue = 1;
    miningSpeed = 1;
}

std::unique_ptr<Unit> ImmortalMiner::copy() const {
    return std::make_unique<ImmortalMiner>();
}

void ImmortalMiner::mine(Player& host) {
    // TODO: host.mineResources(miningSpeed);
}
