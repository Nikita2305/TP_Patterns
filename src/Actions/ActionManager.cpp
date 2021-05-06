#include "Actions/ActionManager.h"
#include "Actions/IrrelevantAction.h"
#include "Actions/AddResourceSquadAction.h"
#include "Actions/AddFightingSquadAction.h"
#include "Units/Miners/SimpleMiner.h"
#include "Units/Miners/ImmortalMiner.h"
#include "Units/Warriors/SimpleWarrior.h"
#include "Units/Warriors/ArmorWarrior.h"
#include "Units/Warriors/SniperWarrior.h"
#include <iostream>
#include <sstream>

ActionManager::ActionManager() {
    queries[getIrrelevantQuery()] = std::make_unique<IrrelevantAction>();

    std::unique_ptr<AddResourceSquadAction> simple_miner = std::make_unique<AddResourceSquadAction>();
    simple_miner->pushUnit(std::make_unique<SimpleMiner>());
    queries["add_simple_miner"] = std::move(simple_miner);

    std::unique_ptr<AddResourceSquadAction> immortal_miner = std::make_unique<AddResourceSquadAction>();
    immortal_miner->pushUnit(std::make_unique<ImmortalMiner>());
    queries["add_immortal_miner"] = std::move(immortal_miner);

    std::unique_ptr<AddResourceSquadAction> mining_squad = std::make_unique<AddResourceSquadAction>();
    mining_squad->pushUnit(std::make_unique<SimpleMiner>());
    mining_squad->pushUnit(std::make_unique<SimpleMiner>());
    queries["add_mining_squad"] = std::move(mining_squad);

    std::unique_ptr<AddFightingSquadAction> simple_warrior = std::make_unique<AddFightingSquadAction>();
    simple_warrior->pushUnit(std::make_unique<SimpleWarrior>());
    queries["add_simple_warrior"] = std::move(simple_warrior);

    std::unique_ptr<AddFightingSquadAction> armor_warrior = std::make_unique<AddFightingSquadAction>();
    armor_warrior->pushUnit(std::make_unique<ArmorWarrior>());
    queries["add_armor_warrior"] = std::move(armor_warrior);

    std::unique_ptr<AddFightingSquadAction> sniper_warrior = std::make_unique<AddFightingSquadAction>();
    sniper_warrior->pushUnit(std::make_unique<SniperWarrior>());
    queries["add_sniper_warrior"] = std::move(sniper_warrior);

    std::unique_ptr<AddFightingSquadAction> fighting_squad = std::make_unique<AddFightingSquadAction>();
    fighting_squad->pushUnit(std::make_unique<ArmorWarrior>());
    fighting_squad->pushUnit(std::make_unique<SniperWarrior>());
    queries["add_fighting_squad"] = std::move(fighting_squad);
}

void ActionManager::execute(Player& player, const Query& query) const {
    auto q = queries.find(query.text);
    if (q == queries.end()) {
        q = queries.find(getIrrelevantQuery());
    }
    q->second->execute(player, query);
}

std::string ActionManager::getIrrelevantQuery() const {
    return "wrong_query";
}

std::string ActionManager::help() const {
    std::stringstream ss;
    for (auto& t: queries) {
        ss << t.first << "\n";
    }
    return ss.str();
}
