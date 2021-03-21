#include "../../include/Commands/DeleteUnitsCommand.h"

DeleteUnitsCommand::DeleteUnitsCommand(std::vector<Unit*>& units): units(units) {}

void DeleteUnitsCommand::execute() {
    std::cout << "DETECTED: " << units.size() << " UNITS" << std::endl;
    for (int i = 0; i < units.size(); i++) {
        delete units[i];
    }
    units.clear();
}