#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../include/Units/Unit.h"
#include "../include/Units/SimpleMiner.h"
#include "../include/Units/TeleportingMiner.h"
#include "../include/Units/ImmortalMiner.h"
#include "../include/Units/SimpleWarrior.h"
#include "../include/Units/ArmorWarrior.h"
#include "../include/Units/SniperWarrior.h"
#include "../include/Commands/Command.h"
#include "../include/Commands/ExitCommand.h"
#include "../include/Commands/DeleteUnitsCommand.h"
#include "../include/Commands/AddUnitCommand.h"

void executeLoop() {
    std::vector<Unit*> units;
    std::map<std::string, Command*> queries;
    queries["exit"] = new ExitCommand();
    queries["delete all"] = new DeleteUnitsCommand(units);

    std::cout << "LOG: Adding prototypes... " << std::endl;
    queries["add simple miner"] = new AddUnitCommand(new SimpleMiner(), units);
    queries["add teleporting miner"] = new AddUnitCommand(new TeleportingMiner(), units);
    queries["add immortal miner"] = new AddUnitCommand(new ImmortalMiner(), units);
    queries["add simple warrior"] = new AddUnitCommand(new SimpleWarrior(), units);
    queries["add armor warrior"] = new AddUnitCommand(new ArmorWarrior(), units);
    queries["add sniper warrior"] = new AddUnitCommand(new SniperWarrior(), units);
    std::cout << std::endl;

    std::cout << "POSSIBLE QUERIES: " << std::endl;
    for (auto t: queries) {
        std::cout << t.first << std::endl;
    }
    std::cout << std::endl;

    while (true) {
        std::cout << "Waiting for the query: " << std::endl;
        std::string query = "";
        std::getline(std::cin, query);
        if (queries.find(query) == queries.end()) {
            std::cout << "There is no such query." << std::endl;
            continue;
        }
        queries[query]->execute();
    }
}

int main() {
    executeLoop();
    return 0;
}
