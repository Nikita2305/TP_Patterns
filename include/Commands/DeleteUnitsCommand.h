class DeleteUnitsCommand;

#pragma once
#include "Command.h"

class DeleteUnitsCommand: public Command {
private:
    std::vector<Unit*>& units;
public:
    DeleteUnitsCommand(std::vector<Unit*>& units);
    void execute() override;
};