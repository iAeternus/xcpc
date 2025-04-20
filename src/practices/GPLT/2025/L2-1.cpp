/*
(((2+3)*4)-(5/(6+7)))
*/
#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    for (char c : s) {
        if (c != ')') {
            st.push(c);
        } else {
            std::string expr;
            while (st.size() >= 2 && st.top() != '(') {
                expr += st.top();
                st.pop();
            }
            st.pop(); // (
            std::reverse(expr.begin(), expr.end());
            std::cout << expr << std::endl;
        }
    }
}