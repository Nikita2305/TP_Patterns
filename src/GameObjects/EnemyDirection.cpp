#include <iostream>
#include "GameObjects/EnemyDirection.h"
#include "GameObjects/Player.h"
#include "Units/UnitSquad.h"

EnemyDirection::EnemyDirection(Player *p1, Player *p2, int length): playerLeft(p1), playerRight(p2), direction(length) {}

void EnemyDirection::addUnit(std::unique_ptr<UnitSquad> squad) {
    bool isForward = squad->isInstance(*playerLeft);
    direction.addUnit(std::move(squad), isForward);
}

void EnemyDirection::tick() {
    direction.tick();
}

void EnemyDirection::draw() {
    direction.draw();
    std::cout << std::endl;
}
