#include <bits/stdc++.h>

int n, m;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> mp(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            std::cin >> x;
            if (x == '*') {
                mp[i][j] = 10;
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (check(nx, ny)) {
                        ++mp[nx][ny];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] >= 10) {
                std::cout << '*';
            } else {
                std::cout << mp[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}