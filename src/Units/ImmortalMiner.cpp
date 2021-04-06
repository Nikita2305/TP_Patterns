#include "Units/ImmortalMiner.h"

ImmortalMiner::ImmortalMiner() {
    healthValue = 25;
    miningSpeed = 26;
}

Unit* ImmortalMiner::copy() {
    return new ImmortalMiner();
}

bool ImmortalMiner::mine() {
    return true;
}
