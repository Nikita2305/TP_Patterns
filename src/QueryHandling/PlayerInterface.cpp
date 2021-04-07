#include "QueryHandling/PlayerInterface.h"
#include <iostream>

PlayerInterface::PlayerInterface(Player& player, std::unique_ptr<IStream>&& _stream): player(player) {
    stream = std::move(_stream);
}

void PlayerInterface::executeAll() {
    stream->update();
    while (stream->hasQuery()) {
        Query query = parse(stream->popFirst());
        // std::cerr << "executing " << query.text << std::endl;
        // TODO: Game.Executor.execute(query);
    }
}

std::unique_ptr<IStream>& PlayerInterface::getStream() {
    return stream;
}

Query PlayerInterface::parse(const std::string& query) const {
    // TODO: Parsing
    return Query(query, std::vector<int>());
}