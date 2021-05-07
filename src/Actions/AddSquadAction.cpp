#include "Actions/AddSquadAction.h"

void AddSquadAction::pushUnit(std::unique_ptr<Unit> unit) {
    members.push_back(std::move(unit));
}