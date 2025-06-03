#include <bits/stdc++.h>

/**
 * 判断是否合法
 */
bool isValid(const std::string& sequence) {
    std::stack<char> st;
    for (char c : sequence) {
        if (c == ')' && !st.empty() && st.top() == '(') {
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    std::string s1 = "(())()";
    std::string s2 = ")()";
    assert(isValid(s1));
    assert(!isValid(s2));
}