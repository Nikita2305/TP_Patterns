#include "Commands/CommandManager.h"
#include <iostream>

CommandManager::CommandManager() {
    // TODO: Init commands here
    // also init Wrong query. Each query is "word1 word2 word3 ... word_n"
    // each word is a sequence of english letters
}

void CommandManager::execute(Player& player, const Query& query) const {
    auto q = queries.find(query.text);
    if (q == queries.end()) {
        q = queries.find(getWrongQuery());
    }
    q->second->execute(player, query.args);
}

std::string CommandManager::getWrongQuery() const {
    return "Wrong query";
}

std::string CommandManager::help() const {
    std::string ret = "";
    for (auto& t: queries) {
        ret += t.first + "\n";
    }
    return ret;
}