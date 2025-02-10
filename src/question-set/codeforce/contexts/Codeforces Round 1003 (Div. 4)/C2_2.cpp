#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<i64> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::sort(b.begin(), b.end());

    i64 x_prev = LLONG_MIN;
    bool ans = true;

    for (int i = 0; i < n; i++) {
        i64 ai = a[i];
        bool tag1 = false;
        i64 tmp1 = ai;
        if (tmp1 >= x_prev) {
            tag1 = true;
        }

        bool tag2 = false;
        i64 tmp2;
        i64 target = x_prev == LLONG_MIN ? LLONG_MIN : x_prev + ai;
        auto it = std::lower_bound(b.begin(), b.end(), target);
        if (it != b.end()) {
            tmp2 = *it - ai;
            if (x_prev == LLONG_MIN || tmp2 >= x_prev) {
                tag2 = true;
            }
        }

        std::vector<i64> cand;
        if (tag1) {
            cand.push_back(tmp1);
        }
        if (tag2) {
            cand.push_back(tmp2);
        }

        if (cand.empty()) {
            ans = false;
            break;
        }

        x_prev = *min_element(cand.begin(), cand.end());
    }

    std::cout << (ans ? "YES" : "NO") << '\n';
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