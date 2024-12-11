/**
 * @see https://www.luogu.com.cn/problem/P7074
 * TODO WA
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int n, m;
int mp[N][N];
bool vis[N][N];

int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};

int max_ans = 0, ans = 0;

void dfs(int x, int y) {
    if (x == n && y == m) {
        max_ans = std::max(max_ans, ans);
        ans = 0;
        return;
    }
    if (vis[x][y] || x < 1 || x > n || y < 1 || y > n) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ans += mp[x][y];
        dfs(nx, ny);
        ans -= mp[x][y];
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> mp[i][j];
        }
    }
    std::cout << max_ans << std::endl;
}