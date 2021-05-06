#include <iostream>
#include <unistd.h>
#include "GameObjects/Game.h"

void clearscreen() {

}

void executeLoop() {
    Game::makeGame();
    Game::getGame().init();
    for (int i = 0; i < 10; i++) {
        Game::getGame().executeQueries();
        Game::getGame().tick();
        Game::getGame().draw();
        sleep(1);
        clearscreen();
    }
}

int main() {
    executeLoop();
    return 0;
}
