#include "QueryHandling/PlayerInterface.h"
#include <iostream>

PlayerInterface::PlayerInterface(Player& player_, std::unique_ptr<IStream> stream_): player(player_), stream(std::move(stream_)) {}

void PlayerInterface::executeAll() {
    stream->update();
    while (stream->hasData()) {
        Query query = parse(stream->extractString());
        // TODO: Game.ActionManager.execute(query);
    }
}

IStream& PlayerInterface::getStream() {
    return *stream.get();
}

Query PlayerInterface::parse(const std::string& query) const {
    std::string text = "";
    std::vector<std::string> args(1, "");
    for (int i = 0; i < query.length(); i++) {
        if (query[i] == ' ') {
            if (i > 0 && query[i - 1] != ' ') {
                args.emplace_back("");
            }
        } else {
            args.back().push_back(query[i]);
        }
    }
    if (args.back().empty()) {
        args.pop_back();
    }
    if (args.empty()) {
        return Query{"Wrong query"}; //TODO: Game.Exec.getWQ()
    }
    text = args[0];
    args.erase(args.begin());
    return Query{text, args};
}