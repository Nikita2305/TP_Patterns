#pragma once
#include "Units/Unit.h"
#include "GameObjects/Player.h"
#include <vector>

class Command {
public:
    virtual void execute(Player& player, const std::vector<int>& args) const = 0;
};
