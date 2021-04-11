#pragma once
#include "Commands/AddSquadCommand.h"

class AddResourceSquadCommand: public AddSquadCommand {
public:
    void execute(Player&, const std::vector<int>&) const override;
};