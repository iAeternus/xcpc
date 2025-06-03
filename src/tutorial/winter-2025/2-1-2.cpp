#include <bits/stdc++.h>

using i64 = long long;
std::unordered_map<int, int> mp;

void solve() {
    mp.clear();
    int n;
    std::cin >> n;
    int score = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        mp[a]++;
        if (mp[a] == 2) {
            ++score;
            mp.erase(a);
        }
    }
    std::cout << score << std::endl;
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