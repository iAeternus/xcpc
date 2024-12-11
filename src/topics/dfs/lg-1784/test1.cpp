/**
 * @see https://www.luogu.com.cn/problem/P1784
 */
#include <bits/stdc++.h>

const int N = 9;
int mp[N][N];
bool row[N][N + 1], col[N][N + 1], grid[3][3][N + 1];

void show() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << mp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    exit(0);
}

bool check(int x, int y, int num) {
    return row[x][num] || col[y][num] || grid[x / 3][y / 3][num];
}

void dfs(int x, int y) {
    if (y == N) {
        y = 0;
        x++;
    }
    if (x == N) {
        show();
        return;
    }

    if (mp[x][y] != 0) {
        dfs(x, y + 1);
        return;
    }

    for (int num = 1; num <= 9; ++num) {
        if (check(x, y, num)) {
            continue;
        }
        mp[x][y] = num;
        row[x][num] = col[y][num] = grid[x / 3][y / 3][num] = true;
        dfs(x, y + 1);
        row[x][num] = col[y][num] = grid[x / 3][y / 3][num] = false;
        mp[x][y] = 0;
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> mp[i][j];
            if (mp[i][j] != 0) {
                row[i][mp[i][j]] = col[j][mp[i][j]] = grid[i / 3][j / 3][mp[i][j]] = true;
            }
        }
    }

    dfs(0, 0);
}