#include "Commands/AddUnitCommand.h"

AddUnitCommand::AddUnitCommand(std::unique_ptr<Unit> _unit) {
    unit = std::move(_unit);
}

void AddUnitCommand::execute(Player& player, const std::vector<int>& args) {
    //player.addUnit(unit->copy()); //may Be Some Customization
}
