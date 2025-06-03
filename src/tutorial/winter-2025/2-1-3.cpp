#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string a;
    std::cin >> a;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] == 'p') {
            std::cout << 'q';
        } else if (a[i] == 'q') {
            std::cout << 'p';
        } else {
            std::cout << a[i];
        }
    }
    std::cout << std::endl;
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