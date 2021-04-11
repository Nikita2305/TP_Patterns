#pragma once
#include "Commands/Command.h"

class IrrelevantCommand: public Command {
public:
    void execute(Player& player, const std::vector<int>& args) const override;
};