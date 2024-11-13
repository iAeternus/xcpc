/**
 * @see https://www.luogu.com.cn/problem/P1904
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int a[N];

int main() {
    int l, r, h;
    while (~scanf("%d %d %d", &l, &h, &r)) {
        for (int i = l; i < r; ++i) {
            a[i] = std::max(h, a[i]);
        }
    }

    h = 0;
    for (int i = 0; i < N; ++i) {
        if (h != a[i]) {
            h = a[i];
            printf("%d %d ", i, a[i]);
        }
    }
}