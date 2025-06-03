// auto 与结构化绑定
#include <bits/stdc++.h>

int main() {
    std::map<int, int> mp = {{1, 1}, {2, 2}, {3, 3}};

    for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << ' ' << it->second << std::endl;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << ' ' << it->second << std::endl;
    }

    // Since C++ 17
    for (const auto& [key, value] : mp) {
        std::cout << key << ' ' << value << std::endl;
    }
}