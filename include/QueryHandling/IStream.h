class IStream;

#pragma once
#include <string>

class IStream {
public:
    virtual bool hasQuery() const = 0;
    virtual std::string popFirst() = 0;
    virtual void pushBack(const std::string&) = 0;
    virtual void update() = 0;
};