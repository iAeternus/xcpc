#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n); // h, cnt
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a[i] = {x, 1};
    }

    i64 ans = 0;
    std::stack<std::pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first < a[i].first) {
            ans += st.top().second;
            st.pop();
        }
        if (!st.empty() && a[i].first == st.top().first) {
            auto x = st.top();
            ans += st.top().second;
            st.pop();
            if (!st.empty()) {
                ++ans;
            }
            st.emplace(x.first, x.second + 1);
        } else {
            if (!st.empty()) {
                ++ans;
            }
            st.push(a[i]);
        }
    }
    std::cout << ans << std::endl;
}