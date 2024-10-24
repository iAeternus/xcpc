#include <bits/stdc++.h>

#define EPS 1e-8

bool equals(double x, double y) {
    return fabs(x - y) < EPS;
}

bool lt(double x, double y) {
    return y - x > EPS;
}

bool gt(double x, double y) {
    return x - y > EPS;
}

bool le(double x, double y) {
    return lt(x, y) || equals(x, y);
}

bool ge(double x, double y) {
    return gt(x, y) || equals(x, y);
}

/**
 * 若 x > y，则 x - y >= -EPS 一定成立
 * 若 x > y 且 x 与 y 接近，则 x - y >= -EPS 一定成立
 * 若 x < y 且 x 与 y 接近，则 x - y >= -EPS 一定不成立
 * 若 x < y，则 x - y >= -EPS 一定不成立
 */
int realGt(double x, double y) {
    return x - y >= -EPS;
}

int realGe(double x, double y) {
    return x - y > -EPS;
}

int main() {
    std::cout << (0.1 + 0.2 == 0.3) << std::endl;
    std::cout << 0.1 + 0.2 << std::endl;
    std::cout << equals(0.1 + 0.2, 0.3) << std::endl;

    std::cout << ge(10, 50) << std::endl;

    std::cout << realGt(0.1 + 0.2000001, 0.3) << std::endl;
    std::cout << realGe(0.1 + 0.2, 0.3) << std::endl;
}