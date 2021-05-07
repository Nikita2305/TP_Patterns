#pragma once
#include <string>

class IStream {
public:
    virtual bool hasData() const = 0;
    virtual std::string extractString() = 0;
    virtual void appendString(const std::string& s) = 0;
    virtual void update() = 0;
};