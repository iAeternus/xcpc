/**
 * @see https://codeforces.com/contest/2025/problem/A
 */
#include <bits/stdc++.h>

int solve(const std::string& s, const std::string& t) {
    int ans = 0;
    int min_len = std::min(s.length(), t.length());
    int i = 0, j = 0;

    for(; i < min_len, j < min_len; ++i, ++j) {
        if(s[i] != t[j]) {
            break;
        }
        ++ans;
    }

    if(ans) {
        ans++;
    }

    return ans + s.length() - i + t.length() - j;
}

int main() {
    int q;
    std::cin >> q;
    
    while(q--) {
        std::string s, t;
        std::cin >> s >> t;
        std::cout << solve(s, t) << std::endl;
    }
}