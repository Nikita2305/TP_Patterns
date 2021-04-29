#pragma once
#include "Actions/AddSquadAction.h"

class AddFightingSquadAction: public AddSquadAction {
public:
    void execute(Player& player, const Query& query) const override;
};