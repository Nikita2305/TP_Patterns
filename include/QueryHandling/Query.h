struct Query;

#pragma once
#include "GameObjects/Player.h"
#include <vector>
#include <string>
#include <memory>

struct Query {
    Query(const std::string&, const std::vector<int>&);
    std::string text;
    std::vector<int> args;
};
