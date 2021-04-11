#include "Commands/AddSquadCommand.h"

void AddSquadCommand::pushUnit(std::unique_ptr<Unit> unit) {
    members.push_back(std::move(unit));
}