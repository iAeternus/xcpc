/**
 * https://www.luogu.com.cn/problem/P5788
 */
#include <bits/stdc++.h>

const int N = 3e6 + 5;
int nums[N], ans[N];
std::stack<int> st;

int main() {
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cin >> nums[i];
    }

    for(int i = n; i >= 1; --i) {
        while(!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        if(st.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = st.top();
        }

        st.push(i);
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
}