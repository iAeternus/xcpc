/**
 * @see https://www.lanqiao.cn/problems/89/learning/?page=1&first_category_id=1&name=%E8%B7%AF%E5%BE%84%E4%B9%8B%E8%B0%9C
 */
/*
Sample Input
4
2 4 3 4
4 3 3 3

Sample Output
0 4 5 1 2 3 7 11 10 9 13 14 15
*/
#include <bits/stdc++.h>

class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

public:
    std::vector<int> pathPuzzle(int col[], int row[], int n) {
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
        std::vector<int> path;

        std::function<bool(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= n) return false;
            if (vis[x][y]) return false;
            if (row[x] == 0 || col[y] == 0) return false;
            // 某个坐标即将变成0，但是左边还存在非0值，因为不可能在回到左边，故剪枝
            if (row[x] == 1 && std::accumulate(row, row + x, 0)) return false;
            if (col[y] == 1 && std::accumulate(col, col + y, 0)) return false;
            row[x]--;
            col[y]--;
            vis[x][y] = true;
            path.push_back(x * n + y);
            if (x == n - 1 && y == n - 1 && std::accumulate(row, row + n, 0) == 0 && std::accumulate(col, col + n, 0) == 0) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                if (dfs(x + dx[i], y + dy[i])) {
                    return true;
                }
            }
            row[x]++;
            col[y]++;
            vis[x][y] = false;
            path.pop_back();
            return false;
        };

        dfs(0, 0);
        return path;
    }
};

int main() {
    int n;
    std::cin >> n;
    int row[n], col[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> row[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> col[i];
    }

    Solution s;
    auto path = s.pathPuzzle(row, col, n);
    for (const auto& it : path) {
        std::cout << it << ' ';
    }
}