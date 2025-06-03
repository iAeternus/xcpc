/**
 * WA
 */
#include <bits/stdc++.h>

using i64 = long long;

struct Node {
    int idx;
    int s;
    std::vector<int> p;
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Node> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].idx = i;
        std::cin >> v[i].s;
        v[i].p.resize(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i].p[j];
        }
    }

    std::sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
        return a.s < b.s;
    });

    bool ok = true;
    int prev_max = -1;
    int cur_max = -1;
    int cur_s = -1;

    for (int i = 0; i < n; ++i) {
        if (i == 0 || v[i].s > v[i - 1].s) {
            prev_max = cur_max;
            cur_max = -1;
            cur_s = v[i].s;
        }

        int ss = 0;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (v[i].p[j] != -1) {
                ss += v[i].p[j];
            } else {
                cnt++;
            }
        }

        int min_score = (i == 0 || v[i].s > v[i - 1].s) ? (prev_max + 1) : (prev_max + 1);
        min_score = std::max(min_score, 0);

        int required_sum = std::max(min_score, ss);
        int sum_max = ss + cnt * k;

        if (sum_max < required_sum) {
            ok = false;
            break;
        }

        int add = required_sum - ss;

        int base = cnt > 0 ? add / cnt : 0;
        int rem = cnt > 0 ? add % cnt : 0;

        int p = 0;
        for (int j = 0; j < m; ++j) {
            if (v[i].p[j] == -1) {
                if (p < rem) {
                    v[i].p[j] = base + 1;
                    p++;
                } else {
                    v[i].p[j] = base;
                }
            }
        }

        int cur_sum = ss + add;
        if (cur_max == -1 || cur_sum > cur_max) {
            cur_max = cur_sum;
        }
    }

    if (!ok) {
        std::cout << "No\n";
        return;
    }

    std::sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
        return a.idx < b.idx;
    });

    std::cout << "Yes\n";
    for (const auto& it : v) {
        for (const auto& jt : it.p) {
            std::cout << jt << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
