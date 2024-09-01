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
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void test() {
    ll a = 34;
    ll b = 85;
    ll x = 0, y = 0;

    std::cout << extend_gcd(a, b, x, y) << std::endl;
    std::cout << x << ' ' << y << std::endl;
}

int main() {
    test();
}