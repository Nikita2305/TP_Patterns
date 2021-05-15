#pragma once
#include "Actions/UserAction.h"

class AddSquadAction: public UserAction {
private:
    std::deque<std::unique_ptr<Unit>> members;
protected:
    std::deque<std::unique_ptr<Unit>> getMembersDeque() const;
public:
    void pushUnit(std::unique_ptr<Unit> unit);
};