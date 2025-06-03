#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }
    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.first < o2.first;
    });

    i64 ans = 0;
    auto[aa, bb] = v[0];
    for(int i = 1; i < n; ++i) {
        if(v[i].first > bb) {
            ans += bb - aa;
            aa = v[i].first;
            bb = v[i].second;
        } else {
            bb = std::max(bb, v[i].second);
        }
    }
    std::cout << ans + bb - aa << std::endl;
}