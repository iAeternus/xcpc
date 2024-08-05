/**
 * https://www.luogu.com.cn/problem/P1440
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
std::deque<std::pair<int, int>> dq;
int s[N];

int main() {
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;

        // 出了窗口的弹出
        if(!dq.empty() && dq.front().first < i - m) {
            dq.pop_front();
        }

        // 此时队头就是最小值
        if(!dq.empty()) {
            std::cout << dq.front().second << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }

        // 把队列尾大于等于x的数弹出，因为它们不会是将来数前m个数中的最小值
        while(!dq.empty() && dq.back().second >= x) {
            dq.pop_back();
        }

        // 把x入队
        dq.push_back({i, x});
    }
}