#include <iostream>
#include <stack>

typedef long long i64;

int main() {
    int n;
    std::cin >> n;
    i64 ans = 0;
    std::stack<int> st;
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        while(!st.empty() && st.top() <= x) {
            st.pop();
        }
        ans += st.size();
        st.push(x);
    }
    std::cout << ans << std::endl;
}