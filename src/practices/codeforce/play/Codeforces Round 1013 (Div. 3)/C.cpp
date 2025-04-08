#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if(n % 2 == 0) {
        std::cout << -1 << std::endl;
        return;
    }
    std::cout << 1 << ' ';
    for(int i = n; i >= 2; --i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
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