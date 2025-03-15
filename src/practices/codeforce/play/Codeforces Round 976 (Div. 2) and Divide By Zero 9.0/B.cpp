/**
 * @see https://codeforces.com/contest/2020/problem/B
 * 只有操作偶数次的灯才是开的
 * 只有完全平方数的因数为奇数个，这些灯操作奇数次后一定是关的
 * 找到最小的n，使得[1, n]排除所有完全平方数后的个数为 k
 * 对于完全平方数 x，其之前的完全平方数（包括自己）个数为 sqrt(x)，所以排除后个数为 x - sqrt(x)
 * 二分答案即可
 */
#include <bits/stdc++.h>

using ll = long long;

ll check(ll x) {
    return x - (ll) sqrtl(x);
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        ll k;
        std::cin >> k;

        ll l = 1, r = 2e18;
        while(l < r) {
            ll mid = l + r >> 1;
            if(check(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        std::cout << r << std::endl;
    }
}