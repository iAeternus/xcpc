#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;

    int q;
    std::cin >> q;
    i64 lazy_tag = 0;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            i64 x;
            std::cin >> x;
            pq.push(x - lazy_tag); // 进来时先把当前的减掉
        } else if (op == 2) {
            i64 x;
            std::cin >> x;
            lazy_tag += x; // 懒标记增加
        } else {
            std::cout << pq.top() + lazy_tag << std::endl; // 出去时一次性把从进来到出去区间内的懒标记加上
            pq.pop();
        }
    }
}