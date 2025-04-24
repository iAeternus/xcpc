#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if(n == 2) {
        std::cout << "Alice\n";
        return;
    } else if(n == 3) {
        std::cout << (s == "Alice" ? "Alice" : "Bob") << std::endl;
    } else {
        int k = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i - 1] >= a[i]) {
                ++k;
            }
        }
        
        if(s == "Alice") {
            std::cout << (k <= 2 ? "Alice" : "Bob") << std::endl;
        } else {
            std::cout << "Bob" << std::endl;
        }
    }
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