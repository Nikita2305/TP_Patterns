#pragma once

#include "GameObjects/Drawable.h"
#include "GameObjects/Tickable.h"
#include <list>
#include <memory>

class Direction;
class UnitSquad;

class Pool: public Drawable, public Tickable {
public:
    Pool(Direction& host);
    void tick() override;
    void draw() override;
    void addUnit(std::unique_ptr<UnitSquad> unitSquad, bool isForward);
    std::list<std::unique_ptr<UnitSquad>>::iterator begin();
    std::list<std::unique_ptr<UnitSquad>>::iterator end();
    std::unique_ptr<UnitSquad> extract(std::list<std::unique_ptr<UnitSquad>>::iterator iterator);
    void set(std::unique_ptr<UnitSquad>, std::list<std::unique_ptr<UnitSquad>>::iterator iterator);
    bool contains(std::list<std::unique_ptr<UnitSquad>>::iterator iterator);
    std::list<std::unique_ptr<UnitSquad>>& getUnits();
private:
    std::list<std::unique_ptr<UnitSquad>> units;
    Direction& host;
};