/**
 * 记忆化dfs求SG值
 */
#include <bits/stdc++.h>

const int N = 1e2 + 3;
const int MAX_N = 1e4 + 3;

// a[i]：可改变当前状态的方式
// f[i]：sg[i]
int k, a[N], f[MAX_N];

int sg(int p) {
    int t;
    bool g[N] = {0};
    for (int i = 0; i < k; ++i) {
        t = p - a[i];
        if (t < 0) {
            break;
        }
        if (f[t] == -1) {
            f[t] = sg(t);
        }
        g[f[t]] = 1;
    }

    for (int i = 0;; ++i) {
        if (!g[i]) {
            return i;
        }
    }
}

int main() {
    // Given
    // 一共有m个石子
    int m = 23;

    // 一共k种取法
    k = 3;
    // 每次可选择取a[i]个石子
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    std::sort(a, a + k);

    // When
    for (int i = 0; i <= m; ++i) {
        f[i] = sg(i);
        std::cout << "sg(" << i << ") = " << f[i] << std::endl;
    }
}