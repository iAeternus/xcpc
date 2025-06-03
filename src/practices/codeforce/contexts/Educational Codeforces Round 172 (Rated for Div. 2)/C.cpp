/**
 * @see https://codeforces.com/contest/2042/problem/C
 */
#include <bits/stdc++.h>

void removeAll(std::string& str, const std::string& pattern) {
    size_t pos = str.find(pattern);
    while (pos != std::string::npos) {
        str.erase(pos, pattern.length());
        pos = str.find(pattern, pos);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::string str;
        std::cin >> n >> k >> str;
        removeAll(str, "10");
        if (str.empty()) {
            std::cout << -1 << std::endl;
            continue;
        }

        for (int i = 0; i < str.length(); ++i) {
        }
    }
}