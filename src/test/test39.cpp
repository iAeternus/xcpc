#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> v(m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[i] = {a, b};
    }
    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.first < o2.first;
    });

    for(int i = 1; i < v.size(); ++i) {
        if((v[i].first - v[i-1].first != v[i].second - v[i-1].second) && (v[i].first - v[i].second <= v[i-1].first)) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}