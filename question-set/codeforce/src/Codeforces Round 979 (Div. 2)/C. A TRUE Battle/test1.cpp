/**
 * @see https://codeforces.com/contest/2030/problem/C
 */
#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    if (s[0] == '1' || s[s.length() - 1] == '1') {
        std::cout << "YES" << std::endl;
        return;
    }

    for (int i = 1; i < s.length() - 1; ++i) {
        if(s[i] == '1' && (s[i - 1] == '1' || s[i + 1] == '1')) {
            std::cout << "YES" << std::endl;
            return;
        }
    }   
    std::cout << "NO" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}