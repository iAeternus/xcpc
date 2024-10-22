/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=1848
 * 模板提，拆开就是取子游戏
 */
#include <bits/stdc++.h>

const int MAX_N = 1e3 + 5;

// 小于1000的斐波那契数
int f[16] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
int sg[MAX_N], s[MAX_N];

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

int m, n, p;

int main() {
    freopen("1.in", "r", stdin);

    getSG(16, MAX_N);
    while (~scanf(" %d %d %d", &m, &n, &p)) {
        if (m == 0 && n == 0 && p == 0) {
            break;
        }

        int xorSum = sg[m] ^ sg[n] ^ sg[p];
        printf("%s\n", xorSum == 0 ? "Nacci" : "Fibo");
    }
}