#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unistd.h>
#include <list>
#include "GameObjects/Game.h"
#include "GameObjects/Player.h"
#include "QueryHandling/PlayerInterface.h"
#include "QueryHandling/BufferStream.h"

void executeLoop() {
    Game::makeGame();
    Game::getGame().init();
    for (int i = 0; i < 10; i++) {
        Game::getGame().executeQueries();
        Game::getGame().tick();
        Game::getGame().draw();
        sleep(1);
    }
}

int main() {
    executeLoop();
    return 0;
}
