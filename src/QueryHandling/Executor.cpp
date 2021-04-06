#include "QueryHandling/Executor.h"
#include <iostream>

Executor::Executor() {
    // TODO: Init commands here
}

void Executor::execute(Player& player, const Query& query) const {
    auto t = queries.find(query.text);
    if (t == queries.end()) {
        return;
    }
    t->second->execute(player, query.args);
}

std::string Executor::help() const {
    std::string ret = "";
    for (auto& t: queries) {
        ret += t.first + "\n";
    }
    return ret;
}