#include "Commands/CommandManager.h"
#include "Commands/IrrelevantCommand.h"
#include "Commands/AddResourceSquadCommand.h"
#include "Commands/AddFightingSquadCommand.h"
#include "Units/Miners/SimpleMiner.h"
#include "Units/Miners/ImmortalMiner.h"
#include "Units/Warriors/SimpleWarrior.h"
#include "Units/Warriors/ArmorWarrior.h"
#include "Units/Warriors/SniperWarrior.h"
#include <iostream>
#include <sstream>

CommandManager::CommandManager() {
    queries[getIrrelevantQuery()] = std::make_unique<IrrelevantCommand>();

    std::unique_ptr<AddResourceSquadCommand> simple_miner = std::make_unique<AddResourceSquadCommand>();
    simple_miner->pushUnit(std::make_unique<SimpleMiner>());
    queries["add simple miner"] = std::move(simple_miner);

    std::unique_ptr<AddResourceSquadCommand> immortal_miner = std::make_unique<AddResourceSquadCommand>();
    immortal_miner->pushUnit(std::make_unique<ImmortalMiner>());
    queries["add immortal miner"] = std::move(immortal_miner);

    std::unique_ptr<AddResourceSquadCommand> mining_squad = std::make_unique<AddResourceSquadCommand>();
    mining_squad->pushUnit(std::make_unique<SimpleMiner>());
    mining_squad->pushUnit(std::make_unique<SimpleMiner>());
    queries["add mining squad"] = std::move(mining_squad);

    std::unique_ptr<AddFightingSquadCommand> simple_warrior = std::make_unique<AddFightingSquadCommand>();
    simple_warrior->pushUnit(std::make_unique<SimpleWarrior>());
    queries["add simple warrior"] = std::move(simple_warrior);

    std::unique_ptr<AddFightingSquadCommand> armor_warrior = std::make_unique<AddFightingSquadCommand>();
    armor_warrior->pushUnit(std::make_unique<ArmorWarrior>());
    queries["add armor warrior"] = std::move(armor_warrior);

    std::unique_ptr<AddFightingSquadCommand> sniper_warrior = std::make_unique<AddFightingSquadCommand>();
    sniper_warrior->pushUnit(std::make_unique<SniperWarrior>());
    queries["add sniper warrior"] = std::move(sniper_warrior);

    std::unique_ptr<AddFightingSquadCommand> fighting_squad = std::make_unique<AddFightingSquadCommand>();
    fighting_squad->pushUnit(std::make_unique<ArmorWarrior>());
    fighting_squad->pushUnit(std::make_unique<SniperWarrior>());
    queries["add fighting squad"] = std::move(fighting_squad);
}

void CommandManager::execute(Player& player, const Query& query) const {
    auto q = queries.find(query.text);
    if (q == queries.end()) {
        q = queries.find(getIrrelevantQuery());
    }
    q->second->execute(player, query.args);
}

std::string CommandManager::getIrrelevantQuery() const {
    return "Wrong query";
}

std::string CommandManager::help() const {
    std::stringstream ss;
    for (auto& t: queries) {
        ss << t.first << "\n";
    }
    return ss.str();
}
