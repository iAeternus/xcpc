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
    std::vector<Node> v(n, Node{0, 0, std::vector<int>(m)});
    for (int i = 0; i < n; ++i) {
        v[i].idx = i;
        int s;
        std::cin >> v[i].s;
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i].p[j];
        }
    }
    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.s < o2.s;
    });
    int cur_s = 0;
    for (int& it : v[0].p) {
        if (it != -1) {
            cur_s += it;
        } else {
            it = 0;
        }
    }
    cur_s += 1;
    for (int i = 1; i < v.size(); ++i) {
        int sum = 0;
        for (int it : v[i].p) {
            if (it != -1) {
                sum += it;
            }
        }
        int new_sum = 0;
        int tmp = cur_s - sum;
        for (int& it : v[i].p) {
            if (it == -1) {
                if (tmp > 0) {
                    int add = std::min(k, tmp);
                    it = add;
                    tmp -= add;
                    new_sum += it;
                } else {
                    it = 0;
                }
            } else {
                new_sum += it;
            }
        }

        if (new_sum < cur_s) {
            std::cout << "No\n";
            return;
        }
        cur_s++;
    }

    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.idx < o2.idx;
    });

    std::cout << "Yes\n";
    for (const auto& it : v) {
        auto a = it.p;
        for (const auto& jt : a) {
            std::cout << jt << ' ';
        }
        std::cout << std::endl;
    }
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