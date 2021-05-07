#include <iostream>
#include "GameObjects/Pool.h"
#include "GameObjects/Direction.h"
#include "Units/UnitSquad.h"
#include "Units/Positions/PoolPosition.h"

Pool::Pool(Direction &host): host(host) {}

void Pool::addUnit(std::unique_ptr<UnitSquad> unitSquad, bool isForward) {
    if (isForward) {
        units.push_front(std::move(unitSquad));
        units.front()->setPosition(std::make_unique<PoolPosition>(host, isForward, units.begin()));
    } else {
        units.push_back(std::move(unitSquad));
        units.back()->setPosition(std::make_unique<PoolPosition>(host, isForward, --units.end()));
    }
}

void Pool::tick() {

}

void Pool::draw() {
    std::cout << " |" << units.size() << "| ";
}

std::list<std::unique_ptr<UnitSquad>>::iterator Pool::begin() {
    return units.begin();
}

std::list<std::unique_ptr<UnitSquad>>::iterator Pool::end() {
    return units.end();
}

std::unique_ptr<UnitSquad> Pool::extract(std::list<std::unique_ptr<UnitSquad>>::iterator iterator) {
    std::unique_ptr<UnitSquad> ret = std::move(*iterator);
    units.erase(iterator);
    return ret;
}

void Pool::set(std::unique_ptr<UnitSquad> unitSquad, std::list<std::unique_ptr<UnitSquad>>::iterator iterator) {
    units.insert(iterator, std::move(unitSquad));
}

bool Pool::contains(std::list<std::unique_ptr<UnitSquad>>::iterator iterator) {
    for (auto& it : units) {
        if (std::addressof(*iterator) == std::addressof(it)) {
            return true;
        }
    }
    return false;
}

std::list<std::unique_ptr<UnitSquad>>& Pool::getUnits() {
    return units;
}
