#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (st.find(a[i]) == st.end()) {
            std::cout << *st.begin() << ' ';
            st.erase(st.begin());
        } else {
            st.erase(a[i]);
            std::cout << a[i] << ' ';
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