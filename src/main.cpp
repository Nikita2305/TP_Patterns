#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unistd.h>
#include "GameObjects/Player.h"
#include "QueryHandling/PlayerInterface.h"
#include "QueryHandling/BufferStream.h"

void executeLoop() {
    // Attention: It is just a simple example of use. Soon class Game will appear.
    // Game between two bots.
    /*
    std::array<Player, 2> players = {Player(), Player()};
    std::array<PlayerInterface, 2> interfaces = {PlayerInterface(players[0], std::make_unique<BufferStream>()), PlayerInterface(players[0], std::make_unique<BufferStream>())};
    for (int iteration = 0; iteration < 10; ++iteration) {
        // tick()
        // draw()
        interfaces[0].getStream()->pushBack("addUnit");
        interfaces[0].executeAll();
        interfaces[1].getStream()->pushBack("addUnit");
        interfaces[1].executeAll();
        sleep(1);
    }
    */
}

int main() {
    executeLoop();
    return 0;
}
