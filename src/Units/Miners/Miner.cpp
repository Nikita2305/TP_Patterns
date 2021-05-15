#include <iostream>
#include "Units/Miners/Miner.h"

void Miner::act(Player& host, const Position& position) {
    mine(host);
}

void Miner::mine(Player& host) {
    // TODO: host.mineResources(miningSpeed);
    std::cout << "+1" << std::endl;
    getHurt(1);
}
