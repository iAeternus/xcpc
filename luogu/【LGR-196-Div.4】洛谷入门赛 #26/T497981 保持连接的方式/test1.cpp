/**
 * https://www.luogu.com.cn/problem/B4024
 */
#include <bits/stdc++.h>

struct Diary {
    int id, cnt;
};

struct Cell {
    std::stack<Diary> diaries;

};

int main() {
    int n, m, k, t;
    std::cin >> n >> m >> k >> t;

    std::vector<std::vector<std::stack<Diary>>> box(n, std::vector<std::stack<Diary>>(m));
    std::vector<std::vector<int>> indexes(n, std::vector<int>(m, 0));

    for (int i = 0; i < t; ++i) {
        int a, x, y;
        std::cin >> a >> x >> y;

        int x1 = x - 1;
        int y1 = y - 1;

        if (box[x1][y1].size() < k) {
            std::cout << -1 << std::endl;
        } else {
            indexes[x1][y1];
        }
        // box[x1][y1].push({a, box[x1][y1].size()});
    }
}