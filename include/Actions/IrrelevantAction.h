#pragma once
#include "Actions/UserAction.h"

class IrrelevantAction: public UserAction {
public:
    void execute(Player& player, const Query& query) const override;
};