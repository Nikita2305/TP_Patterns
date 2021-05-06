#include "GameObjects/Game.h"
#include "Actions/AddResourceSquadAction.h"

void AddResourceSquadAction::execute(Player& player, const Query& query) const {
    try {
        player.sendToResourceDirection(std::make_unique<UnitSquad>(player, getMembersDeque()),
                                    Game::getGame().getResourceDirection(query.getUInt(0)));
    } catch (...) {
        //
    }
}
