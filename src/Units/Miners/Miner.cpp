#include "Units/Miners/Miner.h"

void Miner::act() {
    mine();
}

void Miner::mine() {
    // host.mineResources(1);
    getHurt(1);
}
