/**
 * @see https://www.luogu.com.cn/problem/U523852
 */
#include <bits/stdc++.h>

const int N = 45;
int r, c;
int min_len = INT_MAX, len;
int mp[N][N];
bool vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int len) {
    if (x < 0 || x >= r || y < 0 || y >= c || vis[x][y] || mp[x][y])
        return;

    if (x == r - 1 && y == c - 1) {
        min_len = std::min(min_len, len);
        return;
    }

    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, len + 1);
    }
    vis[x][y] = false;
}

int main() {
    std::cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char c;
            std::cin >> c;
            mp[i][j] = (c == '#');
        }
    }
    dfs(0, 0, 1);
    std::cout << min_len << std::endl;
}