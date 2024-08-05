/**
 * https://www.luogu.com.cn/problem/P1996
 */
#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::list<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    std::list<int>::iterator it = nums.begin();
    while (nums.size() > 1) {
        for (int i = 1; i < m; ++i) {
            ++it;
            // 循环
            if (it == nums.end()) {
                it = nums.begin();
            }
        }
        std::cout << *it << ' ';
        std::list<int>::iterator next = ++it;
        // 注意next的循环
        if (next == nums.end()) {
            next = nums.begin();
        }

        nums.erase(--it);  // 这里--是为了消除上面++的影响
        it = next;
    }
    std::cout << *it;
}