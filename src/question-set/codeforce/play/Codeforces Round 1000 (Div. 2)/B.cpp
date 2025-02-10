#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> ll, rr;
    l--;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (i < r) {
            ll.push_back(x);
        }
        if (i >= l) {
            rr.push_back(x);
        }
    }
    std::sort(ll.begin(), ll.end());
    std::sort(rr.begin(), rr.end());

    std::cout << std::min(std::accumulate(ll.begin(), ll.begin() + r - l, 0LL),
                          std::accumulate(rr.begin(), rr.begin() + r - l, 0LL))
              << std::endl;
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