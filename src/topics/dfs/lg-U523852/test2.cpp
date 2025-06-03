/**
 * @brief 广搜做法
 */
#include <bits/stdc++.h>

const int N = 45;
int r, c;
int min_len = INT_MAX, len;
int mp[N][N];
bool vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, len;
};

int bfs() {
    std::queue<Node> q;
    q.push({0, 0, 1});
    vis[0][0] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == r - 1 && cur.y == c - 1) {
            return cur.len;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny] || mp[nx][ny]) {
                continue;
            }
            vis[nx][ny] = true;
            q.push({nx, ny, cur.len + 1});
        }
    }
    return -1;
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

    std::cout << bfs() << std::endl;
}