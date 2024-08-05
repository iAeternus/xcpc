/**
 * https://www.luogu.com.cn/problem/P1440
 * 
 * 这题用cin、cout洛谷会超时
 */
#include <bits/stdc++.h>

std::deque<std::pair<int, int>> dq;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);

        // 出了窗口的弹出
        if(!dq.empty() && dq.front().first < i - m) {
            dq.pop_front();
        }

        // 此时队头就是最小值
        if(!dq.empty()) {
            printf("%d\n", dq.front().second);
        } else {
            puts("0");
        }

        // 把队列尾大于等于x的数弹出，因为它们不会是将来数前m个数中的最小值
        while(!dq.empty() && dq.back().second >= x) {
            dq.pop_back();
        }

        // 把x入队
        dq.push_back({i, x});
    }
}