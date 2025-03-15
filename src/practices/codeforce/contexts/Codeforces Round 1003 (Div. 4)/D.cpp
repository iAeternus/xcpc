#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            sum += a[i][j];
        }
        a[i].push_back(sum);
    }
    std::sort(a.begin(), a.end(), [](auto& v1, auto& v2) {
        return v1[v1.size() - 1] > v2[v2.size() - 1];
    });
    std::vector<int> res, prefix(n * m, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            res.push_back(a[i][j]);
        }
    }
    for(int i = 1; i < res.size(); ++i) {
        prefix[i] = prefix[i - 1] + res[i];
    }
    int ans = 0;
    for(int i = 0; i < n * m; ++i) {
        ans += prefix[i];
    }
    std::cout << ans << std::endl;

    // int ans = 0, k = m;
    // for(const auto& num : res) {
    //     ans += k * num;
    //     k--;
    // }    
    // std::cout << ans << std::endl;

    // int ans = 0;
    // for(int i = 0; i < n; ++i) {
    //     int line_sum = a[i][a[i].size() - 1];
    //     ans = m * line_sum;
    //     int tmp = 0, idx = 1;
    //     for(int j = 1; j < m; ++j) {
    //         tmp += a[i][j] * idx++;
    //     }
    //     ans -= tmp;
    // }
    // std::cout << ans << std::endl;
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