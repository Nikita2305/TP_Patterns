#include <iostream>
#include "GameObjects/Player.h"
#include "GameObjects/EnemyDirection.h"
#include "GameObjects/ResourceDirection.h"
#include "Units/UnitSquad.h"

Player::Player(int resources, int health): resources(resources), health(health) {}

void Player::sendToEnemyDirection(std::unique_ptr<UnitSquad> unitSquad, EnemyDirection& enemyDirection) {
    enemyDirection.addUnit(std::move(unitSquad));
}

void Player::sendToResourceDirection(std::unique_ptr<UnitSquad> unitSquad, ResourceDirection& resourceDirection) {
    resourceDirection.addUnit(std::move(unitSquad));
}

void Player::draw() {
    std::cout << " / " << resources << " / " << health << " / " << std::endl;
}
