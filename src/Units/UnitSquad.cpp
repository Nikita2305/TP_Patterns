#include "Units/UnitSquad.h"

UnitSquad::UnitSquad(Player& host_, const std::deque<std::unique_ptr<Unit>>& members_, std::unique_ptr<Position> position_):
    host(host_), members(members_), position(std::move(position_)) {}

void UnitSquad::move() {
    std::unique_ptr<Position> newPosition = position->next();
    if (newPosition->isFreeToSet()) {
        std::unique_ptr<UnitSquad> thisUnitSquad = position->extractUnitSquad();
        newPosition->setUnitSquad(std::move(thisUnitSquad));
        position = std::move(newPosition);
    }
}

void UnitSquad::act() {
    for (auto& t: members) {
        t->act(host, *position);
    }
}

void UnitSquad::getHurt(int attackValue) {
    members.front()->getHurt(attackValue);
    if (members.front()->getHealth() <= 0) {
        members.pop_front();
    }
    if (members.empty()) {
        die();
    }
}

void UnitSquad::die() {
    std::unique_ptr<UnitSquad> thisUnitSquad = position->extractUnitSquad();
}

bool UnitSquad::isInstance(const Player& player) const {
    return (&host == &player);
}