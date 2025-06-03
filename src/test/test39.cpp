#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    // std::cin >> n >> m;

    // v[0] = {0, 0};
    // for (int i = 1; i <= m; ++i) {
    //     std::cin >> v[i].first >> v[i].second;
    // }
    // std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
    //     return o1.first < o2.first;
    // });

    // for (int i = 1; i < v.size(); ++i) {
    //     if(v[i].second > v[i - 1].second) { // 扩大
    //         if(v[i].first - v[i - 1].first < v[i].second - v[i - 1].second) {
    //             std::cout << "No\n";
    //             return;
    //         }
    //     } else if(v[i].second < v[i - 1].second) { // 缩小
    //         if(v[i].first - v[i - 1].first < v[i].second + 1) {
    //             std::cout << "No\n";
    //             return;
    //         }
    //     } else { // 不变
    //         if(v[i].first - v[i - 1].first < v[i - 1].second + 1) {
    //             std::cout << "No\n";
    //             return;
    //         }
    //     }
    // }
    // std::cout << "Yes\n";

    std::cin >> n >> m;
    std::vector<std::pair<int, int>> v(m + 1);
    v[0] = {0, 0};
    for (int i = 1; i <= m; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }
    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.first < o2.first;
    });
    for (int i = 1; i < v.size(); ++i) {
        if (!((v[i].first - v[i - 1].first == v[i].second - v[i - 1].second) || v[i].first - v[i].second > v[i - 1].first)) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
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