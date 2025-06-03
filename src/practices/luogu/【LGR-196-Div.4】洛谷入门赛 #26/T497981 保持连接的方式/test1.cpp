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
            auto st = box[x1][y1];
            int min_id = INT_MAX;
            while(!st.empty()) {
                min_id = std::min(min_id, st.top().id);
                st.pop();
            }

            std::stack<Diary> tmp;
            while(!box[x1][y1].empty() && box[x1][y1].top().id != min_id) {
                tmp.push(box[x1][y1].top());
                box[x1][y1].pop();
            }
            box[x1][y1].pop();

            std::cout << min_id << ' ' << tmp.size() << std::endl;

            while(!tmp.empty()) {
                box[x1][y1].push(tmp.top());
                tmp.pop();
            }
        }
        box[x1][y1].push({a, int(box[x1][y1].size())});
    }
}