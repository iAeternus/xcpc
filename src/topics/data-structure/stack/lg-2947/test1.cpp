/**
 * https://www.luogu.com.cn/problem/P2947
 * 
 * 单调栈
 */
#include <bits/stdc++.h>

const int N = 1e6 + 5;
int h[N], ans[N];
std::stack<int> st;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }

    for (int i = n; i >= 1; --i) {
        // 比我矮，不是我的仰望对象
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }

        if (st.empty()) {
            // 没有仰望对象
            ans[i] = 0;
        } else {
            // 有
            ans[i] = st.top();
        }

        st.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
}