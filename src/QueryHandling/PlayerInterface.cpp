#include "QueryHandling/PlayerInterface.h"
#include <iostream>

PlayerInterface::PlayerInterface(Player& player_, std::unique_ptr<IStream> stream_): player(player_), stream(std::move(stream_)) {}

void PlayerInterface::executeAll() {
    stream->update();
    while (stream->hasData()) {
        Query query = parse(stream->extractString());
        // TODO: Game.Executor.execute(query);
    }
}

IStream& PlayerInterface::getStream() {
    return *stream.get();
}

Query PlayerInterface::parse(const std::string& query) const {
    std::string text = "";
    std::vector<int> args;
    int bound;
    for (bound = 1; bound + 1 < query.size(); bound++) {
        if (query[bound] == ' ' && isdigit(query[bound + 1]) && isalpha(query[bound - 1])) {
            break;
        }
    }
    if (bound == query.size()) {
        return Query("Wrong query", std::vector<int>()); //TODO: Game.Exec.getWQ()
    }
    for (int i = 0; i < bound; i++) {
        if (isalpha(query[i]) || query[i] == ' ') {
            text += query[i];
        } else {
            return Query("Wrong query", std::vector<int>()); //TODO: Game.Exec.getWQ()
        }
    }
    bool isNumber = false;
    for (int i = bound + 1; i < query.size(); i++) {
        if (isdigit(query[i])) {
            if (isNumber) {
                args.back() = args.back() * 10 + (query[i] - '0');
            } else {
                args.push_back(query[i] - '0');
            }
            isNumber = true;
        } else if (query[i] == ' ') {
            isNumber = false;
        } else {
            return Query("Wrong query", std::vector<int>()); //TODO: Game.Exec.getWQ()
        }
    }
    return Query(text, args);
}