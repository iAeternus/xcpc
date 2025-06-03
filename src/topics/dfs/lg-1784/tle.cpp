/**
 * @see https://www.luogu.com.cn/problem/P1784
 */
#include <bits/stdc++.h>

const int N = 9;
std::vector<std::vector<int>> mp(N, std::vector<int>(N));

bool check(int x, int y, int num) {
    // 检查行列
    for (int i = 0; i < N; ++i) {
        if (mp[x][i] == num || mp[i][y] == num) {
            return false;
        }
    }

    // 检查宫
    int sx = x / 3 * 3;
    int sy = y / 3 * 3;
    int ex = sx + 3;
    int ey = sy + 3;
    for (int i = sx; i < ex; ++i) {
        for (int j = sy; j < ey; ++j) {
            if (mp[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool dfs() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mp[i][j] != 0) {
                continue;
            }
            // 枚举 1~N
            for (int num = 1; num <= N; ++num) {
                if (!check(i, j, num)) {
                    continue;
                }
                mp[i][j] = num;
                if (dfs()) {
                    return true;
                }
                mp[i][j] = 0;
            }
            return false; // 无解
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> mp[i][j];
        }
    }
    dfs();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << mp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}