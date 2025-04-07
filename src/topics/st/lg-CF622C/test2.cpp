/**
 * dp[i]: a[1...i]中最靠右的与a[i]不同的元素的下标
 * 
 * if a[i] != a[i - 1]
 *      dp[i] = i - 1
 * else: 
 *      dp[i] = dp[i - 1]
 * 
 * 对于每个query，有
 * if a[r] != x
 *      r
 * else if dp[r] >= l
 *      dp[r]
 * 
 * O(n + m)
 */
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        dp[i] = a[i] != a[i - 1] ? i - 1 : dp[i - 1];
    }

    while(m--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        if(a[r] != x) {
            std::cout << r << std::endl;
        } else if(dp[r] >= l) {
            std::cout << dp[r] << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }
}