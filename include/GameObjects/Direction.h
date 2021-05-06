#pragma once

#include "GameObjects/Drawable.h"
#include "GameObjects/Tickable.h"
#include "GameObjects/Pool.h"
#include <vector>
#include <memory>

class UnitSquad;

class Direction: public Drawable, public Tickable {
public:
    Direction(int length);
    void tick() override;
    void draw() override;
    void addUnit(std::unique_ptr<UnitSquad>, bool isForward);
    int size();
    Pool& getLeftPool();
    Pool& getRightPool();
    std::unique_ptr<UnitSquad> extract(int index);
    bool isEmpty(int index) const;
    void set(std::unique_ptr<UnitSquad> unitSquad, int index);
private:
    Pool poolLeft;
    Pool poolRight;
    std::vector<std::unique_ptr<UnitSquad>> units;
};