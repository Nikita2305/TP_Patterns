#pragma once
#include "GameObjects/Player.h"
#include <vector>
#include <string>
#include <memory>

struct Query {
    std::string text;
    std::vector<std::string> args;
    int getUInt(int index) const;
};
