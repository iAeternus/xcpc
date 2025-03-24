#include <bits/stdc++.h>

using i64 = long long;

struct C {
    int t, l, h;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<C> v(1);
    for(int i = 0; i < n; ++i) {
        int t, l, h;
        std::cin >> t >> l >> h;
        v.push_back({t, l, h});
    }
    std::sort(std::next(v.begin()), v.end(), [](const auto& a, const auto& b) {
        return a.t < b.t;
    });

    int l = m, h = m;
    for(int i = 1; i < v.size(); ++i) {
        int d = v[i].t - v[i - 1].t;
        l -= d, h += d;
        if(l > v[i].h || h < v[i].l) {
            std::cout << "NO" << std::endl;
            return;
        }
        l = std::max(l, v[i].l);
        h = std::min(h, v[i].h);
    }
    std::cout << "YES" << std::endl;
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