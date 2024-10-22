/**
 * @see https://www.luogu.com.cn/problem/P4549
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 21;
int a[N];


ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for(int i = 2; i <= n; ++i) {
        a[i] = gcd(a[i], a[i - 1]);
    }

    std::cout << abs(a[n]) << std::endl;
}
