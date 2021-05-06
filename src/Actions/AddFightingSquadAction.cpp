#include "Actions/AddFightingSquadAction.h"
#include "GameObjects/Game.h"

void AddFightingSquadAction::execute(Player& player, const Query& query) const {
    try {
        player.sendToEnemyDirection(std::make_unique<UnitSquad>(player, getMembersDeque()),
                                    Game::getGame().getEnemyDirection(query.getUInt(0)));
    } catch (...) {
        //
    }
}
