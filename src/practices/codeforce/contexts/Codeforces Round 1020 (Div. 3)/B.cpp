#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    if(n == x) {
        for(int i = 0; i < n; ++i) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        return;
    }

    std::vector<int> a(n);
    a[a.size() - 1] = x;
    std::vector<int> tmp;
    for(int i = 0; i < n; ++i) {
        if(i != x) {
            tmp.push_back(i);
        }
    }
    for(int i = 0; i < tmp.size(); ++i) {
        a[i] = tmp[i];
    }
    for(int it : a) {
        std::cout << it << ' ';
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