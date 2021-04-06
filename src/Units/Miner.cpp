#include "Units/Miner.h"

bool Miner::mine() {
    if (healthValue == 0) {
        return false;
    }
    healthValue--;
    return true;
}
