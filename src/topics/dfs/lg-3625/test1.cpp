/**
 * @see https://www.luogu.com.cn/problem/B3625
 */
#include <bits/stdc++.h>

const int N = 103;
int n, m;
std::string a[N];
bool vis[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool can = false;

void dfs(int x, int y) {
    if (can) return;
    if (x < 0 || x >= n || y < 0 || y > m) {
        return;
    }
    if (a[x][y] == '#' || vis[x][y]) {
        return;
    }
    if (x == n - 1 && y == m - 1) {
        can = true;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        vis[x][y] = true;
        dfs(x + dx[i], y + dy[i]);
        // vis[x][y] = false;
    }
}

// void dfs(int x, int y) {
//     if(x == n - 1 && y == m - 1) {
//         can = true;
//         return;
//     }
//     vis[x][y] = true;
//     for(int i = 0; i < 4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[x][y] || a[nx][ny] == '#') {
//             continue;
//         }
//         dfs(nx, ny);
//     }
// }

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    dfs(0, 0);
    std::cout << (can ? "Yes" : "No") << std::endl;
}