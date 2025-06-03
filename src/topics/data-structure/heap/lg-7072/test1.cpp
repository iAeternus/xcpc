#include <bits/stdc++.h>

int main() {
    int n, w;
    std::cin >> n >> w;
    std::priority_queue<int> a;                                   // 大根堆
    std::priority_queue<int, std::vector<int>, std::greater<>> b; // 小根堆

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        if (b.empty() || b.top() < x) {
            b.push(x);
        } else {
            a.push(x);
        }
        int k = std::max(1, i * w / 100);
        while (b.size() > k) {
            a.push(b.top());
            b.pop();
        }
        while (b.size() < k) {
            b.push(a.top());
            a.pop();
        }
        std::cout << b.top() << ' ';
    }
}