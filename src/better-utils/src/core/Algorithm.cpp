#include "Algorithm.h"

bool Algorithm::checkRange(std::size_t n, std::size_t l, std::size_t r) {
    return l <= r && r <= n;
}