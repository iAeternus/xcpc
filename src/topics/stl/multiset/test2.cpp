#include <bits/stdc++.h>

struct X {
    int a, b;
};

// 按b逆序
struct Cmp {
    bool operator()(const X& o1, const X& o2) const {
        return o1.b > o2.b;
    }
};

int main() {
    std::multiset<X, Cmp> ms = {{1, 1}, {1, 2}, {1, 3}};
    /*
    1 3
    1 2
    1 1
    */
    for (const auto& it : ms) {
        std::cout << it.a << ' ' << it.b << std::endl;
    }
}