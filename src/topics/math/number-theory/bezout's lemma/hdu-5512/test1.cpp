/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=5512
 */
#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool is_odd(int x) {
    return x & 1;
}

int main() {
    // freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        printf("Case #%d: %s\n", i, is_odd(n / gcd(a, b)) ? "Yuwgna" : "Iaka");
    }
}