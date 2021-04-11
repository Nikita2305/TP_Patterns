#pragma once
#include "Commands/Command.h"

class AddSquadCommand: public Command {
private:
    std::deque<std::unique_ptr<Unit>> members;
public:
    void pushUnit(std::unique_ptr<Unit> unit);
};