#pragma once
#include "Commands/Command.h"
#include "QueryHandling/Query.h"
#include <unordered_map>
#include <string>
#include <memory>

class CommandManager {
public:
    CommandManager();
    void execute(Player& player, const Query& query) const;
    std::string getIrrelevantQuery() const;
    std::string help() const;
private:
    std::unordered_map<std::string, std::unique_ptr<Command>> queries;
};