#include <bits/stdc++.h>

using i64 = long long;

int n, k;

struct Node {
    i64 x;
};

struct cmp {
    bool operator()(const Node& o1, const Node& o2) {
        return (o1.x % k) < (o2.x % k);
    }
};

void solve() {
    std::cin >> n >> k;
    std::priority_queue<Node, std::vector<Node>, cmp> pq;
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        pq.push({x});
    }
    int m;
    std::cin >> m;

    while (m >= 0 && pq.top().x % k != 0) {
        i64 add = k - pq.top().x % k;
        m -= add;
        if (m < 0) {
            break;
        }
        i64 tmp = pq.top().x + add;
        pq.pop();
        pq.push({tmp});
    }
    i64 ans = std::max(0, m / k);
    while (!pq.empty()) {
        ans += pq.top().x / k;
        pq.pop();
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}