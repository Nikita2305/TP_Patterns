#include "Commands/AddUnitCommand.h"

AddUnitCommand::AddUnitCommand(Unit* unit, std::vector<Unit*>& units): unit(unit), units(units) {}

AddUnitCommand::~AddUnitCommand() {
    delete unit;
}

void AddUnitCommand::execute() {
    units.push_back(unit->copy());
}
