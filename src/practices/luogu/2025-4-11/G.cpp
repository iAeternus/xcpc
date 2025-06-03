#include <bits/stdc++.h>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> b, g;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'B') {
            b.emplace(a[i], i + 1);
        } else {
            g.emplace(a[i], i + 1);
        }
    }

    int cnt = 0;
    std::vector<std::pair<int, int>> ans;
    while (!b.empty() && !g.empty()) {
        auto [a_g, idx_g] = g.top();
        auto [a_b, idx_b] = b.top();
        g.pop();
        b.pop();
        ++cnt;
        ans.emplace_back(std::min(idx_g, idx_b), std::max(idx_g, idx_b));
    }

    std::cout << cnt << std::endl;
    for (const auto& [min_idx, max_idx] : ans) {
        std::cout << min_idx << ' ' << max_idx << std::endl;
    }
}