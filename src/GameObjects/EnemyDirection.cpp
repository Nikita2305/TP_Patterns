#include <iostream>
#include "GameObjects/EnemyDirection.h"
#include "GameObjects/Player.h"
#include "Units/UnitSquad.h"

EnemyDirection::EnemyDirection(Player& playerLeft, Player& playerRight, int length): playerLeft(playerLeft), playerRight(playerRight), direction(length) {}

void EnemyDirection::addUnit(std::unique_ptr<UnitSquad> unitSquad) {
    bool isForward = unitSquad->isInstance(playerLeft);
    direction.addUnit(std::move(unitSquad), isForward);
}

void EnemyDirection::tick() {
    direction.tick();
}

void EnemyDirection::draw() {
    direction.draw();
    std::cout << std::endl;
}
