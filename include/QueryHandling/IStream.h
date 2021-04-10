class IStream;

#pragma once
#include <string>

class IStream {
public:
    virtual bool hasData() const = 0;
    virtual std::string extractString() = 0;
    virtual void appendString(const std::string&) = 0;
    virtual void update() = 0;
};