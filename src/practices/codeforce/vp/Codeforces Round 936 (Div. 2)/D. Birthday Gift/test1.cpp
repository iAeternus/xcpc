/**
 * @see https://codeforces.com/contest/1946/problem/D
 * @see https://mp.weixin.qq.com/s/8IizRy5jAx3Z_75U00CccQ
 */
#include <bits/stdc++.h>

int n, x;

int get_bit(int num, int i) {
    return num >> i & 1;
}

void solve() {
    std::cin >> n >> x;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    int res = -1;

    // can[i]: 表示是否可以将第 i 个元素和第 i + 1 个元素隔离（i < n）
    std::vector<bool> can(n + 1, true);
    for (int j = 29; j >= 0; --j) {
        int sign = 1;
        if (get_bit(x, j)) {
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (get_bit(a[i], j)) {
                    sign ^= 1;
                }
                if (can[i] && sign) {
                    ++cnt;
                }
            }
            if (sign) {
                res = std::max(res, cnt);
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (get_bit(a[i], j)) {
                    sign ^= 1;
                }
                if (!sign) {
                    can[i] = 0;
                }
            }
            if (!sign) {
                std::cout << res << '\n';
                return;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += can[i];
    }

    res = std::max(res, sum);

    std::cout << res << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}