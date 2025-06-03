#include <bits/stdc++.h>

const int N = 10;
int n, m, t, sx, sy, fx, fy;
int mp[N][N];
bool vis[N][N];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int ans = 0;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ++ans;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] != 1) {
            vis[x][y] = true;
            dfs(nx, ny);
            vis[x][y] = false;
        }
    }
}

int main() {
    std::cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        mp[x][y] = 1;
    }
    dfs(sx, sy);
    std::cout << ans << std::endl;
}