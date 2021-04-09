#include "QueryHandling/Executor.h"
#include <iostream>

Executor::Executor() {
    // TODO: Init commands here
    // also init Wrong query. Each query is "word1 word2 word3 ... word_n"
    // each word is a sequence of english letters
}

void Executor::execute(Player& player, const Query& query) const {
    auto q = queries.find(query.text);
    if (q == queries.end()) {
        q = queries.find(getWrongQuery());
    }
    q->second->execute(player, query.args);
}

std::string Executor::getWrongQuery() const {
    return "Wrong query";
}

std::string Executor::help() const {
    std::string ret = "";
    for (auto& t: queries) {
        ret += t.first + "\n";
    }
    return ret;
}