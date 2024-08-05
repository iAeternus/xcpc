/**
 * https://www.luogu.com.cn/problem/P1540
 */
#include <bits/stdc++.h>

const int N = 1e3 + 3;
bool hash[N] = {false};
std::queue<int> mem;

int main() {
    int m, n;
    std::cin >> m >> n;

    int cnt = 0;
    while (n--) {
        int en;
        std::cin >> en;
        if (!hash[en]) {
            ++cnt;
            mem.push(en);
            hash[en] = true;
            while (mem.size() > m) {
                hash[mem.front()] = false;
                mem.pop();
            }
        }
    }

    std::cout << cnt << std::endl;
}