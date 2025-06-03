#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    if (s.length() == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    int idx = -1;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] != '0') {
            idx = i;
            break;
        }
    }

    int cnt = 0;
    for (int i = 0; i < idx; ++i) {
        if (s[i] != '0') {
            ++cnt;
        }
    }
    for (int i = idx + 1; i < s.length(); ++i) {
        if (s[i] == '0') {
            ++cnt;
        }
    }

    std::cout << cnt << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}