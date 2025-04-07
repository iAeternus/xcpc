/**
 * @see https://www.cnblogs.com/hyrule-link/p/3867481.html
 * 把每个数的因子存在因子表中，倒序查找最大的因子个数满足条件的数即为最大gcd
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 1e4 + 2;
int s[N];

void solve() {
    memset(s, 0, sizeof s);

    int n, k;
    std::cin >> n >> k;

    int ma = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ma = std::max(ma, x);
        int sq = std::sqrt(x);
        for (int j = 1; j <= sq; ++j) {
            if (x % j == 0) {
                s[j]++;
                if (x / j != j) {
                    s[x / j]++;
                }
            }
        }
    }

    for (int i = ma; i >= 1; --i) {
        if (s[i] >= k) {
            std::cout << i << std::endl;
            return;
        }
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