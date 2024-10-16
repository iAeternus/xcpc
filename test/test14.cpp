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

int main() {
    std::cout << (0.1 + 0.2 == 0.3) << std::endl;
    std::cout << 0.1 + 0.2 << std::endl;
    std::cout << equals(0.1 + 0.2, 0.3) << std::endl;

    std::cout << ge(10, 50) << std::endl;
}