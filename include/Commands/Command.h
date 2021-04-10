class Command;

#pragma once
#include <vector>
#include "Units/Unit.h"
#include "GameObjects/Player.h"

class Command {
public:
    virtual void execute(Player&, const std::vector<int>&) = 0;
};
