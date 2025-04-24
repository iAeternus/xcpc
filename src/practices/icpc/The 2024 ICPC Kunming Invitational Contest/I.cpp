#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<std::pair<char, int>> v;
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && s[i] == s[j]) ++j;
        v.emplace_back(s[i], j - i);
    }
    if (v.size() == 1) {
        auto [c, cnt] = v[0];
        std::cout << cnt / 2 << std::endl;
        return;
    }
    // 处理首尾相同
    if (v.front().first == v.back().first) {
        v.front().second += v.back().second;
        v.pop_back();
    }
    int ans = 0, ok = 0;
    for (const auto& [c, cnt] : v) {
        ans += cnt / 2;
        ok |= (cnt % 2 == 0);
    }
    std::cout << ans - ok << std::endl;
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