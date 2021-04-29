#pragma once
#include "Actions/AddSquadAction.h"

class AddResourceSquadAction: public AddSquadAction {
public:
    void execute(Player& player, const Query& query) const override;
};