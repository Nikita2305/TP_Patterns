#include "QueryHandling/Query.h"

Query::Query(const std::string& _text, const std::vector<int>& _args) {
    args = std::move(_args);
    text = std::move(_text);
}