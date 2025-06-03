#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i] >> v[i];
    }

    std::stack<int> st;
    std::vector<int> ans(n + 1);
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && h[st.top()] < h[i]) {
            ans[i] += v[st.top()]; // 左
            st.pop();
        }
        if (!st.empty()) {
            ans[st.top()] += v[i]; // 右
        }
        st.push(i);
    }

    int max_ans = 0;
    for (int i = 1; i <= n; ++i) {
        max_ans = std::max(max_ans, ans[i]);
    }
    std::cout << max_ans << std::endl;
}