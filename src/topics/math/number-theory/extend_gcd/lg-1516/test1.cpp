/**
 * @see https://www.luogu.com.cn/problem/P1516
 */
#include <bits/stdc++.h>

using ll = long long;

/**
 * 扩展欧几里得算法
 * 求解gcd的同时求解 ax + by = gcd(a, b) 的一个整数特解 x y
 * @par a 第一个数
 * @par b 第二个数
 * @par x 整数特解 x
 * @par y 整数特解 y
 */
ll extend_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ll x, y, m, n, L;
    std::cin >> x >> y >> m >> n >> L;

    ll a = n - m;
    ll b = L;
    ll c = x - y;

    if (a < 0) {
        a = -a;
        c = -c;
    }

    ll d = extend_gcd(a, b, x, y);

    if (c % d) {
        std::cout << "Impossible\n";
    } else {
        ll mod = b / d;
        std::cout << ((x * (c / d)) % mod + mod) % mod; // x * (c / d)可能为负
    }
}