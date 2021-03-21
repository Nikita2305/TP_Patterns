class AddUnitCommand;

#pragma once
#include "Command.h"

class AddUnitCommand: public Command {
private:
    std::vector<Unit*>& units;
    Unit* unit;
public:
    AddUnitCommand(Unit*, std::vector<Unit*>&);
    ~AddUnitCommand() override;
    void execute() override;
};