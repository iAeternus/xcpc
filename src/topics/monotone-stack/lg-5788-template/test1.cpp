#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1), ans(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> v[i];
    }
    
    std::stack<int> st;
    for(int i = n; i >= 1; --i) {
        while(!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
}