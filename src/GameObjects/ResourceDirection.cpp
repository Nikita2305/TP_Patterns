#include <iostream>
#include "GameObjects/ResourceDirection.h"
#include "GameObjects/Player.h"
#include "Units/UnitSquad.h"

ResourceDirection::ResourceDirection(Player *p1, Player *p2, int length): playerLeft(p1), playerRight(p2), directionLeft(length), directionRight(length) {}

void ResourceDirection::addUnit(std::unique_ptr<UnitSquad> squad) {
    bool isForward = squad->isInstance(*playerLeft);
    if (isForward) {
        directionLeft.addUnit(std::move(squad), isForward);
    } else {
        directionRight.addUnit(std::move(squad), isForward);
    }
}

void ResourceDirection::tick() {

}

void ResourceDirection::draw() {
    directionLeft.draw();
    std::cout << " % ";
    directionRight.draw();
    std::cout << std::endl;
}
