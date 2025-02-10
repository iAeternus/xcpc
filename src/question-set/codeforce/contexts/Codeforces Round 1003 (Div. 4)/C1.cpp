#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int b;
    std::deque<int> a;
    a.push_front(INT_MIN);
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    std::cin >> b;

    for(int i = 1; i < a.size(); ++i) {
        if(a[i - 1] <= a[i]) {
            if(a[i - 1] <= b - a[i]) {
                a[i] = std::min(a[i], b - a[i]);
            }
        } else {
            if(a[i - 1] <= b - a[i]) {
                a[i] = b - a[i];
            } else {
                std::cout << "NO" << std::endl;
                return;
            }
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}