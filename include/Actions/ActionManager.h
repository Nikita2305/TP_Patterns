#pragma once
#include "Actions/UserAction.h"
#include "QueryHandling/Query.h"
#include <unordered_map>
#include <string>
#include <memory>

class ActionManager {
public:
    ActionManager();
    void execute(Player& player, const Query& query) const;
    std::string help() const;
private:
    std::string getIrrelevantQuery() const;
    std::unordered_map<std::string, std::unique_ptr<UserAction>> queries;
};