#include "../../include/Units/SimpleMiner.h"

SimpleMiner::SimpleMiner() {
    std::cout << "SimpleMiner added" << std::endl;
    healthValue = 5;
    miningSpeed = 6;
}

SimpleMiner::~SimpleMiner() {
    std::cout << "SimpleMiner deleted" << std::endl;
}

Unit* SimpleMiner::copy() {
    return new SimpleMiner();
}