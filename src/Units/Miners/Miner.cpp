#include "Units/Miners/Miner.h"

void Miner::act(Player& host, const Position& position) {
    mine(host);
}

void Miner::mine(Player& host) {
    // TODO: host.mineResources(miningSpeed);
    getHurt(1);
}
