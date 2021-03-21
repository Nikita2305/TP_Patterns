#include "../../include/Units/ImmortalMiner.h"

ImmortalMiner::ImmortalMiner() {
    std::cout << "ImmortalMiner added" << std::endl;
    healthValue = 25;
    miningSpeed = 26;
}

ImmortalMiner::~ImmortalMiner() {
    std::cout << "ImmortalMiner deleted" << std::endl;
}

Unit* ImmortalMiner::copy() {
    return new ImmortalMiner();
}

bool ImmortalMiner::mine() {
    std::cout << "Mined: " << miningSpeed << " resources" << std::endl;
    return true;
}