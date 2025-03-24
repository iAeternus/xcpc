#include <bits/stdc++.h>

int min3(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main() {
    assert(min3(1, 2, 3) == 1);
    assert(min3(1, 1, 1) == 1);
    assert(min3(3, 2, 1) == 1);
}