/**
 * @see https://www.luogu.com.cn/problem/P1129
 */
#include <bits/stdc++.h>

const int N = 203;
int n, match[N];
bool a[N][N], vis[N];

bool dfs(int x) {
    for(int i = 1; i <= n; ++i) {
        if(!vis[i] && a[x][i]) {
            vis[i] = true;
            if(!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        std::fill(match + 1, match + 1 + n, 0);
        std::cin >> n;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                std::cin >> a[i][j];
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans += dfs(i);
            std::fill(vis + 1, vis + 1 + n, false);
        }

        std::cout << (ans >= n ? "Yes" : "No") << std::endl;
    }
}