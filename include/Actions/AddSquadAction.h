#pragma once
#include "Actions/UserAction.h"

class AddSquadAction: public UserAction {
private:
    std::deque<std::unique_ptr<Unit>> members;
public:
    void pushUnit(std::unique_ptr<Unit> unit);
};