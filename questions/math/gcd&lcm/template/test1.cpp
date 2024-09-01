#include <bits/stdc++.h>

using ll = long long;

/**
 * 求最大公约数
 * @par a 第一个数
 * @par b 第一个数
 * @return 计算二者的最大公约数
 */
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

/**
 * 求最小公倍数
 * @par a 第一个数
 * @par b 第一个数
 * @return 计算二者的最小公倍数
 */
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void test() {
    ll a = 34;
    ll b = 85;

    std::cout << gcd(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
}

int main() {
    test();
}