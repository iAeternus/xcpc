/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=1730
 * 将两个子的距离看做石子的数量，就变成了Nim博弈
 */
#include <bits/stdc++.h>

int main() {
    freopen("1.in", "r", stdin);

    int n, m;
    while (~scanf(" %d %d", &n, &m)) {
        int xorSum = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);

            int p = abs(x - y) - 1;
            xorSum ^= p;
        }

        printf("%s\n", xorSum == 0 ? "BAD LUCK!" : "I WIN!");
    }
}