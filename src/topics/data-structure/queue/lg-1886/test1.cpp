/**
 * https://www.luogu.com.cn/problem/P1886
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
int a[N];
std::deque<int> dq;

int main() {
    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    // 找最小值
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && a[dq.front()] > a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            std::cout << a[dq.front()] << ' ';
        }
    }

    std::cout << std::endl;

    // 找最大值
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && a[dq.front()] < a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            std::cout << a[dq.front()] << ' ';
        }
    }

    std::cout << std::endl;
}