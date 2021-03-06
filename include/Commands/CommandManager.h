class CommandManager;

#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "Commands/Command.h"
#include "QueryHandling/Query.h"

class CommandManager {
public:
    CommandManager();
    void execute(Player&, const Query&) const;
    std::string getWrongQuery() const;
    std::string help() const;
private:
    std::unordered_map<std::string, std::unique_ptr<Command>> queries;
};