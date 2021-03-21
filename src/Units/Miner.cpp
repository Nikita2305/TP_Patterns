#include "../../include/Units/Miner.h"

bool Miner::mine() {
    if (healthValue == 0) {
        std::cout << "Failed: ";
        return false;
    }
    healthValue--;
    std::cout << "Mined: " << miningSpeed << " resources" << std::endl;
    return true;
}