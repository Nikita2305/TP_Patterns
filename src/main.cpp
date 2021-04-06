#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Units/Unit.h"
#include "Units/SimpleMiner.h"
#include "Units/TeleportingMiner.h"
#include "Units/ImmortalMiner.h"
#include "Units/SimpleWarrior.h"
#include "Units/ArmorWarrior.h"
#include "Units/SniperWarrior.h"
#include "Commands/Command.h"
#include "Commands/ExitCommand.h"
#include "Commands/DeleteUnitsCommand.h"
#include "Commands/AddUnitCommand.h"

void executeLoop() {
    // Example of Use
    std::vector<Unit*> units;
    std::unordered_map<std::string, Command*> queries;
    queries["exit"] = new ExitCommand();
    queries["delete all"] = new DeleteUnitsCommand(units);

    queries["add simple miner"] = new AddUnitCommand(new SimpleMiner(), units);
    queries["add teleporting miner"] = new AddUnitCommand(new TeleportingMiner(), units);
    queries["add immortal miner"] = new AddUnitCommand(new ImmortalMiner(), units);
    queries["add simple warrior"] = new AddUnitCommand(new SimpleWarrior(), units);
    queries["add armor warrior"] = new AddUnitCommand(new ArmorWarrior(), units);
    queries["add sniper warrior"] = new AddUnitCommand(new SniperWarrior(), units);
}

int main() {
    executeLoop();
    return 0;
}
