#include <bits/stdc++.h>

const int N = 20;
int n, m;
int cnt;
int like[N][N], ans[N];
bool vis[N];

void dfs(int idx) {
    if (idx == n) {
        ++cnt;
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i] << ' ';
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < m; ++j) {
        if (like[idx][j] && !vis[j]) {
            ans[idx] = j;
            vis[j] = true;
            dfs(j + 1);
            vis[j] = false;
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> like[i][j];
        }
    }
    dfs(0);
}