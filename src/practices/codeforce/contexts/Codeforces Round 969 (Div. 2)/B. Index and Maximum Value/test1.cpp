/**
 * @see https://codeforces.com/contest/2007/problem/B
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
int a[N];

int main() {
    // freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int v_max = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            v_max = std::max(a[i], v_max);
        }

        while (m--) {
            char op;
            int l, r;
            scanf(" %c %d %d", &op, &l, &r);

            if(v_max >= l && v_max <= r) {
                v_max += (op == '+' ? 1 : -1);
            }

            printf("%d ", v_max);
        }
        putchar('\n');
    }
}