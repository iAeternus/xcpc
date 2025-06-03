#include <bits/stdc++.h>

// [lower, upper)
int nextInt(int lower, int upper) {
    return rand() % (upper - lower) + lower;
}

int main() {
    srand((unsigned)time(nullptr));

    for (int i = 0; i < 100; ++i) {
        std::cout << nextInt(-10, 10) << ' ';
    }
    std::cout << std::endl;
}