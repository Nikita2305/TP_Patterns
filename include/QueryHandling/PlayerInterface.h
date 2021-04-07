class PlayerInterface;

#pragma once
#include "GameObjects/Player.h"
#include "QueryHandling/IStream.h"
#include "QueryHandling/Query.h"
#include <memory>
#include <string>

class PlayerInterface {
public:
    PlayerInterface(Player&, std::unique_ptr<IStream>&&);
    void executeAll();
    std::unique_ptr<IStream>& getStream();
private:
    Player& player;
    std::unique_ptr<IStream> stream;
    Query parse(const std::string&) const;
};