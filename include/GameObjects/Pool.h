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
    void addUnit(std::unique_ptr<UnitSquad>, bool isForward);
    std::list<std::unique_ptr<UnitSquad>>::iterator begin();
    std::list<std::unique_ptr<UnitSquad>>::iterator end();
    std::unique_ptr<UnitSquad> extract(std::list<std::unique_ptr<UnitSquad>>::iterator);
    void set(std::unique_ptr<UnitSquad>, std::list<std::unique_ptr<UnitSquad>>::iterator);
    bool contains(std::list<std::unique_ptr<UnitSquad>>::iterator);
private:
    std::list<std::unique_ptr<UnitSquad>> units;
    Direction& host;
};