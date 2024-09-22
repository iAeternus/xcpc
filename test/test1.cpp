#include <bits/stdc++.h>

int main() {
    std::set<std::pair<int, int>> st = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    // for(int i = 0; i < st.size(); ++i) {
    //     std::cout << st[i].first << ' ' << std::endl;
    // }

    for (const auto& it : st) {
        std::cout << it.first << ' ' << it.second << std::endl;
    }

    // C++ 17
    for (const auto& [x, y] : st) {
        std::cout << x << ' ' << y << std::endl;
    }
}