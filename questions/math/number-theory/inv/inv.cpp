#include <bits/stdc++.h>

using LL = long long;
const LL M = 1e9 + 7;
#define INV 1

LL qpow(LL a, LL n, LL m) {
    LL ans = 1;
    while(n) {
        if(n & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}

#if INV == 1
/*
费马小定理求乘法逆元
要求b与m互质
*/
LL inv(LL b, LL m) {
    return qpow(b, m - 2, m);
}

void test() {
    std::cout << qpow(2, 10, M) << std::endl;
    std::cout << inv(2, M) << std::endl;
}

#elif INV == 2
/*
扩展欧几里得算法求乘法逆元
*/
LL exgcd(LL a, LL b, LL& x, LL& y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }

    LL res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

LL inv(LL b, LL m) {
    LL x, y;
    LL d = exgcd(b, m, x, y);
    return d == 1 ? x : 0;
}

void test() {
    std::cout << inv(2, M) << std::endl;
}
#endif

int main() {
    test();
}