/**
 * https://www.luogu.com.cn/problem/B4022
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;

struct Music {
    int idx, category;

    bool operator<(const Music& m) {
        return this->category < m.category;
    }
} musics[N];

int main() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int c;
        std::cin >> c;

        musics[i].idx = i;
        musics[i].category = c;
    }

    std::sort(musics + 1, musics + n + 1);

    int cnt = n / m;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i; j <= n; j += cnt) {
            std::cout << musics[j].idx << std::endl;
        }
    }
}