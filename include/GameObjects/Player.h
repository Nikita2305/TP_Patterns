#pragma once

#include "GameObjects/Drawable.h"
#include <memory>

class UnitSquad;
class ResourceDirection;
class EnemyDirection;

class Player: public Drawable {
public:
    Player(int resources, int health);
    void draw() override;
    void heal(int health);
    void sendToResourceDirection(std::unique_ptr<UnitSquad>, ResourceDirection&);
    void sendToEnemyDirection(std::unique_ptr<UnitSquad> , EnemyDirection&);
private:
    int resources;
    int health;
};