#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if(n == 1 || n % 4 == 0) {
        std::cout << "impossible\n";
        return;
    }

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        a[i] = i;
        if(i && i % 4 == 0) {
            std::swap(a[i], a[i - 1]);
        }
    }
    std::swap(a[0], a[1]);
    
    for(int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
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