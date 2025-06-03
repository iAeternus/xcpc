/**
 * https://www.luogu.com.cn/problem/P1160
 */
#include <bits/stdc++.h>

const int N = 1e5 + 9;

std::list<int> nums;
std::list<int>::iterator pos[N]; // 同学i的迭代器
bool vis[N];                     // 优化

int main() {
    int n;
    std::cin >> n;

    nums.push_front(1);
    pos[1] = nums.begin();

    for (int i = 2; i <= n; ++i) {
        int k, p;
        std::cin >> k >> p;

        if (p == 0) {
            pos[i] = nums.insert(pos[k], i);
        } else {
            auto next = std::next(pos[k]);
            pos[i] = nums.insert(next, i);
        }
    }

    int m;
    std::cin >> m;
    while (m--) {
        int x;
        std::cin >> x;
        if (!vis[x]) {
            nums.erase(pos[x]);
        }
        vis[x] = true;
    }

    for (auto num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}