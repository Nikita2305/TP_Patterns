#pragma once

#include "GameObjects/Drawable.h"
#include "GameObjects/Tickable.h"
#include "GameObjects/Direction.h"
#include <memory>

class Player;
class UnitSquad;

class EnemyDirection: public Drawable, public Tickable {
public:
    EnemyDirection(Player& playerLeft, Player& playerRight, int length);
    void tick() override;
    void draw() override;
    void addUnit(std::unique_ptr<UnitSquad> unitSquad);
private:
    Player& playerLeft;
    Player& playerRight;
    Direction direction;
};