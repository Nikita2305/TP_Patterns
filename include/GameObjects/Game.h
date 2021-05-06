#pragma once

#include "QueryHandling/PlayerInterface.h"
#include "Actions/ActionManager.h"
#include "GameObjects/EnemyDirection.h"
#include "GameObjects/ResourceDirection.h"
#include "GameObjects/Player.h"

class Game {
public:
    static void makeGame();
    static Game& getGame();
    void init();
    void tick();
    void draw();
    void executeQueries();
    EnemyDirection& getEnemyDirection(int);
    ResourceDirection& getResourceDirection(int);
    Player& getPlayer(int);
    ActionManager& getActionManager();
private:
    Game() = default;
    static Game* game;
    ActionManager actionManager;
    std::vector<Player> players;
    std::vector<PlayerInterface> interfaces;
    std::vector<EnemyDirection> enemyDirections;
    std::vector<ResourceDirection> resourceDirections;
    std::vector<Drawable*> drawableObjects;
    std::vector<Tickable*> tickableObjects;
};