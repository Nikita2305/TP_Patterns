#include "QueryHandling/Query.h"

int Query::getUInt(int index) const {
    std::string value;
    try {
        value = args[index];
    } catch (...) {
        throw;
    }
    int ret = 0;
    for (auto t : value) {
        if (!isdigit(t)) {
            throw std::runtime_error("NaN");
        }
        ret = ret * 10 + (t - '0');
    }
    return ret;
}
