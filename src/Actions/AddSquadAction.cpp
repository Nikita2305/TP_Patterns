#include "Actions/AddSquadAction.h"

void AddSquadAction::pushUnit(std::unique_ptr<Unit> unit) {
    members.push_back(std::move(unit));
}

std::deque<std::unique_ptr<Unit>> AddSquadAction::getMembersDeque() const {
    std::deque<std::unique_ptr<Unit>> ret;
    for (auto& t: members) {
        ret.push_back(t->copy());
    }
    return ret;
}
