/**
 * @see https://www.luogu.com.cn/problem/P1455
 */
#include <bits/stdc++.h>

const int N = 1e4 + 3;
int p[N], v[N], fa[N];
int dp[N]; // dp[j]: 现有的钱为 j，能买到的最大价值为 dp[j]

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    if(x == fa[x]) {
        return x;
    }
    return fa[x] = query(fa[x]);
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if(r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}

int main() {
    int n, m, w;
    std::cin >> n >> m >> w;
    init(n);
    for(int i = 1; i <= n; ++i) {
        std::cin >> p[i] >> v[i];
    }
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        merge(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(i != fa[i]) {
            int r = query(i);
            p[r] += p[i];
            p[i] = 0;
            v[r] += v[i];
            v[i] = 0;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = w; j >= p[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - p[i]] + v[i]);
        }
    }
    std::cout << dp[w] << std::endl;
}