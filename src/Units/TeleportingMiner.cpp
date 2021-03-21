#include "../../include/Units/TeleportingMiner.h"

TeleportingMiner::TeleportingMiner() {
    std::cout << "TeleportingMiner added" << std::endl;
    healthValue = 15;
    miningSpeed = 16;
}

TeleportingMiner::~TeleportingMiner() {
    std::cout << "TeleportingMiner deleted" << std::endl;
}

Unit* TeleportingMiner::copy() {
    return new TeleportingMiner();
}