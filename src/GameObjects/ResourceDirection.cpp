#include <iostream>
#include "GameObjects/ResourceDirection.h"
#include "GameObjects/Player.h"
#include "Units/UnitSquad.h"

ResourceDirection::ResourceDirection(Player& playerLeft, Player& playerRight, int length): playerLeft(playerLeft), playerRight(playerRight), directionLeft(length), directionRight(length) {}

void ResourceDirection::addUnit(std::unique_ptr<UnitSquad> unitSquad) {
    bool isForward = unitSquad->isInstance(playerLeft);
    if (isForward) {
        directionLeft.addUnit(std::move(unitSquad), isForward);
    } else {
        directionRight.addUnit(std::move(unitSquad), isForward);
    }
}

void ResourceDirection::tick() { // TODO: разбить в тики дирекшнов и т.п.
    for (auto it = directionLeft.getUnits().rbegin(); it != directionLeft.getUnits().rend(); ++it) {
        if (*it) {
            (*it)->move();
        }
    }
    for (auto it = directionLeft.getLeftPool().getUnits().rbegin(); it != directionLeft.getLeftPool().getUnits().rend(); it++) {
        (*it)->move();
    }
    for (auto it = directionRight.getUnits().begin(); it != directionRight.getUnits().end(); ++it) {
        if (*it) {
            (*it)->move();
        }
    }
    for (auto it = directionRight.getRightPool().getUnits().begin(); it != directionRight.getRightPool().getUnits().end(); it++) {
        (*it)->move();
    }
    for (auto it = directionLeft.getRightPool().getUnits().begin(); it != directionLeft.getRightPool().getUnits().end(); ++it) {
        (*it)->act();
    }
    for (auto it = directionRight.getLeftPool().getUnits().begin(); it != directionRight.getLeftPool().getUnits().end(); ++it) {
        (*it)->act();
    }
}

void ResourceDirection::draw() {
    directionLeft.draw();
    std::cout << " % ";
    directionRight.draw();
    std::cout << std::endl;
}
