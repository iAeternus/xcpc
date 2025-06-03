#include <bits/stdc++.h>

using ll = long long;

/**
 * 快速幂
 * @note O(log n)
 * @note 存在溢出风险
 * @par a 底数
 * @par n 指数
 * @return 计算 a ^ n
 */
int fast_pow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

/**
 * 取模快速幂
 * @note O(log n)
 * @par a 底数
 * @par n 指数
 * @par m 模数
 * @return 计算 (a ^ n) % m
 */
ll fast_pow(ll a, ll n, ll m) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}

int main() {
    std::cout << fast_pow(2, 10) << std::endl;     // 1024
    std::cout << fast_pow(2, 10, 10) << std::endl; // 4
}