#include <bits/stdc++.h>

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mp(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < m; ++j) {
            mp[i][j] = str[j] - '0';
        }
    }

    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
    int ans = 0;
    auto bfs = [&](int x, int y) {
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;
        while(!q.empty()) {
            auto [rx, ry] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = rx + dx[i];
                int ny = ry + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mp[nx][ny] != 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] != 0 && !vis[i][j]) {
                bfs(i, j);
                ++ans;
            }
        }
    }
    std::cout << ans << std::endl;
}