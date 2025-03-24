#include <bits/stdc++.h>

void clear(std::stack<int>& st) {
    while(!st.empty()) {
        st.pop();
    }
}

int main() {
    int n;
    std::cin >> n;
    std::stack<int> a, b;
    int max_len = 0, cnt = 0;
    bool tag = true;
    for(int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        if(tag) {
            a.push(c);
            tag = false;
            continue;
        }
        if(c < a.top()) {
            a.push(c);
        } else if(b.empty() || c > b.top()) {
            b.push(c);
        } else {
            ++cnt;
            max_len = std::max(max_len, int(a.size()));
            clear(a);
            while(!b.empty() && b.top() > c) {
                a.push(b.top());
                b.pop();
            }
            a.push(c);
        }
    }
    if(!a.empty()) {
        ++cnt;
        max_len = std::max(max_len, int(a.size()));
    }
    if(!b.empty()) {
        ++cnt;
        max_len = std::max(max_len, int(b.size()));
    }
    std::cout << cnt << ' ' << max_len << std::endl;
}