/**
 * @see http://poj.org/problem?id=1141
 */
#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cin >> str;
    std::stack<char> st;
    for(char c : str) {
        if(c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if(st.top() == '(') {
                
            }
        }
    }
}