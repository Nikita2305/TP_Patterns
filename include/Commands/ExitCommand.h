class ExitCommand;

#pragma once
#include "Command.h"

class ExitCommand: public Command {
public:
    void execute() override;
};
