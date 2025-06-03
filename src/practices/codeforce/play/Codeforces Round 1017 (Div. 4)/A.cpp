#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::getline(std::cin, s);
    s = " " + s;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i - 1] == ' ') {
            std::cout << s[i];
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    std::cin.get();

    while (t--) {
        solve();
    }

    return 0;
}