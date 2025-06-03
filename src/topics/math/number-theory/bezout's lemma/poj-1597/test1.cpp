/**
 * @see http://poj.org/problem?id=1597
 */
#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    freopen("in.txt", "r", stdin);

    int step, mod;
    while (~scanf("%d %d", &step, &mod)) {
        int d = gcd(step, mod);
        if (d == 1) {
            puts("Good Choice");
        } else {
            puts("Bad Choice");
        }
        putchar('\n');
    }
}