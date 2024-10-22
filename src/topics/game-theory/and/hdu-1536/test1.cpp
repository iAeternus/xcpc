/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=1536
 */
#include <bits/stdc++.h>

const int N = 1e2 + 3;
const int MAX_N = 1e4 + 5;
int k, m, l, h, f[N], sg[MAX_N], s[MAX_N];

void getSG(int numF, int n) {
    memset(sg, 0, sizeof(sg));
    for (int i = 1; i <= n; ++i) {
        memset(s, 0, sizeof(s));
        for (int j = 0; f[j] <= i && j < numF; ++j) {
            s[sg[i - f[j]]] = 1;
        }

        for (int j = 0;; ++j) {
            if (!s[j]) {
                sg[i] = j;
                break;
            }
        }
    }
}

int main() {
    // freopen("1.in", "r", stdin);

    while (~scanf(" %d", &k)) {
        if (k == 0) {
            break;
        }

        for (int i = 0; i < k; ++i) {
            scanf("%d", &f[i]);
        }
        std::sort(f, f + k);
        getSG(k, MAX_N);

        scanf("%d", &m);
        while (m--) {
            scanf("%d", &l);
            int xorSum = 0;
            for (int i = 0; i < l; ++i) {
                scanf("%d", &h);
                xorSum ^= sg[h];
            }
            printf("%c", xorSum == 0 ? 'L' : 'W');
        }
        putchar('\n');
    }
}