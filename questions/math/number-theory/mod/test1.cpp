#include <bits/stdc++.h>

using ll = long long;

/**
 * 乘法取模
 * 连续执行 a * 2和 b / 2，直到 b为 0
 * @note m > a 时 mul会出错
 * @par a 乘数
 * @par b 乘数
 * @par m 模数
 * @return 计算 (a * b) % m
 */
ll mul(ll a, ll b, ll m) {
    a %= m;  // 防止溢出
    b %= m;
    ll res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a = 0x7877665544332211;
    ll b = 0x7988776655443322;
    ll m = 0x998776655443322;

    std::cout << (a % m) * (b % m) << std::endl; // 4985444552033402426 wrong
    std::cout << mul(a, b, m) << std::endl; // 411509877096934416 right
}