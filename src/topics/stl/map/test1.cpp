#include <bits/stdc++.h>

int main() {
    std::map<int, int> mp = {{1, 1}, {2, 1}, {3, 1}};

    // since c++ 17
    for (const auto& [key, val] : mp) {
        std::cout << key << ' ' << val << std::endl;
    }

    // since c++ 11
    for (const auto& it : mp) {
        std::cout << it.first << ' ' << it.second << std::endl;
    }
}