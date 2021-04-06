#include "Units/SimpleMiner.h"

SimpleMiner::SimpleMiner() {
    healthValue = 5;
    miningSpeed = 6;
}

Unit* SimpleMiner::copy() {
    return new SimpleMiner();
}
