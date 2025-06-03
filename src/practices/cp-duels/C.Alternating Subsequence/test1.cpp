/**
 * @see https://codeforces.com/problemset/problem/1343/C
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 2e5 + 3;
ll a[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        ll ans = 0, max_ans = a[1];
        for (int i = 2; i <= n; ++i) {
            if (a[i] * max_ans > 0) { // 同号
                max_ans = std::max(max_ans, a[i]);
            } else {
                ans += max_ans;
                max_ans = a[i];
            }
        }

        std::cout << ans + max_ans << std::endl;
    }
}