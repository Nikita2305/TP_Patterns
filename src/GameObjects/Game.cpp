#include "QueryHandling/StandardInputStream.h"
#include "GameObjects/Game.h"

Game* Game::game = nullptr;

void Game::makeGame() {
    game = new Game();
}

Game& Game::getGame() {
    return *game;
}

void Game::init() {
    for (int i = 0; i < 2; i++) {
        players.push_back(Player(100, 100));
        drawableObjects.push_back(&players[i]);
        interfaces.push_back(PlayerInterface(players[i], std::make_unique<StandardInputStream>()));
    }
    for (int i = 0; i < 2; i++) {
        enemyDirections.push_back(EnemyDirection(&players[0], &players[1], 5));
        drawableObjects.push_back(&enemyDirections[i]);
        tickableObjects.push_back(&enemyDirections[i]);
    }
    for (int i = 0; i < 1; i++) {
        resourceDirections.push_back(ResourceDirection(&players[0], &players[1], 2));
        drawableObjects.push_back(&resourceDirections[i]);
        tickableObjects.push_back(&resourceDirections[i]);
    }
}

void Game::executeQueries() {
    interfaces[0].getStream().appendString("add_simple_miner");
    for (auto &interface : interfaces) {
        interface.executeAll();
    }
}

void Game::tick() {
    for (auto &object : tickableObjects) {
        object->tick();
    }
}

void Game::draw() {
    for (auto &object : drawableObjects) {
        object->draw();
    }
}

EnemyDirection& Game::getEnemyDirection(int index) {
    return enemyDirections[index];
}

ResourceDirection& Game::getResourceDirection(int index) {
    return resourceDirections[index];
}

Player& Game::getPlayer(int index) {
    return players[index];
}

ActionManager& Game::getActionManager() {
    return actionManager;
}
