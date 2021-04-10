class AddUnitCommand;

#pragma once
#include "Command.h"
#include <memory>

class AddUnitCommand: public Command {
private:
    std::unique_ptr<Unit> unit;
public:
    AddUnitCommand(std::unique_ptr<Unit>);
    void execute(Player&, const std::vector<int>&) override;
};