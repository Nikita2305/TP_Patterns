#pragma once
#include "Units/Unit.h"
#include "GameObjects/Player.h"
#include "Units/Positions/Position.h"
#include <queue>
#include <memory>

class UnitSquad {
public:
    UnitSquad(Player& host_, const std::deque<std::unique_ptr<Unit>>& members_, std::unique_ptr<Position> position_);
    void move();
    void act();
    void getHurt(int attackValue);
    void die();
    bool isInstance(const Player& player) const;
private:
    std::deque<std::unique_ptr<Unit>> members;
    std::unique_ptr<Position> position;
    Player& host;
};