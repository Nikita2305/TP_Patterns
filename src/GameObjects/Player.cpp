#include "GameObjects/Player.h"
#include "GameObjects/EnemyDirection.h"
#include "GameObjects/ResourceDirection.h"
#include "Units/UnitSquad.h"

Player::Player(int resources, int health): resources(resources), health(health) {}

void Player::sendToEnemyDirection(std::unique_ptr<UnitSquad> squad, EnemyDirection& enemyDirection) {
    enemyDirection.addUnit(std::move(squad));
}

void Player::sendToResourceDirection(std::unique_ptr<UnitSquad> squad, ResourceDirection& resourceDirection) {
    resourceDirection.addUnit(std::move(squad));
}

void Player::draw() {

}
