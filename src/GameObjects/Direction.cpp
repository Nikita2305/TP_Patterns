#include <iostream>
#include "GameObjects/Direction.h"
#include "Units/UnitSquad.h"

Direction::Direction(int length): poolLeft(*this), poolRight(*this), units(length) {}

void Direction::addUnit(std::unique_ptr<UnitSquad> squad, bool isForward) {
    if (isForward) {
        poolLeft.addUnit(std::move(squad), isForward);
    } else {
        poolRight.addUnit(std::move(squad), isForward);
    }
}

void Direction::tick() {

}

void Direction::draw() {
    poolLeft.draw();
    for (auto &t : units) {
        std::cout << (bool)(t);
    }
    poolRight.draw();
}

int Direction::size() {
    return units.size();
}

Pool& Direction::getLeftPool() {
    return poolLeft;
}

Pool& Direction::getRightPool() {
    return poolRight;
}

std::unique_ptr<UnitSquad> Direction::extract(int index) {
    return std::move(units[index]);
}

bool Direction::isEmpty(int index) const {
    return units[index] == nullptr;
}

void Direction::set(std::unique_ptr<UnitSquad> unitSquad, int index) {
    units[index] = std::move(unitSquad);
}
