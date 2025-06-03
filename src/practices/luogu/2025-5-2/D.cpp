#include <bits/stdc++.h>

const int N = 2e4 + 3;
int d[N];

int main() {
    int n;
    std::cin >> n;
    int min_ = INT_MAX, max_ = 0;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
        min_ = std::min(min_, v[i].first);
        max_ = std::max(max_, v[i].second);
    }
    if (min_ < 0) {
        for (auto& [a, b] : v) {
            a += -min_;
            b += -min_;
        }
        max_ += -min_;
    }
    for (const auto& [a, b] : v) {
        d[a]++;
        d[b]--;
    }
    for (int i = 1; i < max_; ++i) {
        d[i] += d[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < max_; ++i) {
        if (d[i] != 0) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}