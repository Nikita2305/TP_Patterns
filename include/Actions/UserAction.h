#pragma once
#include "Units/Unit.h"
#include "GameObjects/Player.h"
#include "QueryHandling/Query.h"
#include <vector>

class UserAction {
public:
    virtual void execute(Player& player, const Query& query) const = 0;
};
