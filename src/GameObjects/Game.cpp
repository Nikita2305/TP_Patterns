#include <iostream>
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
        players.emplace_back(100, 100);
    }
    for (int i = 0; i < players.size(); i++) {
        drawableObjects.push_back(&players[i]);
        interfaces.emplace_back(players[i], std::make_unique<StandardInputStream>());
    }
    for (int i = 0; i < 1; i++) {
        resourceDirections.emplace_back(&players[0], &players[1], 2);
    }
    for (int i = 0; i < resourceDirections.size(); i++) { // второй проход - борьба с реаллокацией
        drawableObjects.push_back(&resourceDirections[i]);
        tickableObjects.push_back(&resourceDirections[i]);
    }
    for (int i = 0; i < 2; i++) {
        enemyDirections.emplace_back(&players[0], &players[1], 5);
    }
    for (int i = 0; i < enemyDirections.size(); i++) {
        drawableObjects.push_back(&enemyDirections[i]);
        tickableObjects.push_back(&enemyDirections[i]);
    }
}

void Game::executeQueries() {
    interfaces[0].getStream().appendString("add_simple_miner 0"); // TODO: example
    for (auto &interface : interfaces) {
        interface.executeAll();
    }
}

void Game::tick() {
    for (auto object : tickableObjects) {
        object->tick();
    }
}

void Game::draw() {
    for (Drawable* object : drawableObjects) {
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
