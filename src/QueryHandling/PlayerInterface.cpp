#include "QueryHandling/PlayerInterface.h"
#include <iostream>

PlayerInterface::PlayerInterface(Player& player, std::unique_ptr<IStream> _stream): player(player) {
    stream = std::move(_stream);
}

void PlayerInterface::executeAll() {
    stream->update();
    while (stream->hasQuery()) {
        Query query = parse(stream->popFirst());
        // TODO: Game.Executor(query);
    }
}

std::unique_ptr<IStream>& PlayerInterface::getStream() {
    return stream;
}

Query PlayerInterface::parse(const std::string& query) {
    // TODO: Parsing
    return Query(query, std::vector<int>());
}