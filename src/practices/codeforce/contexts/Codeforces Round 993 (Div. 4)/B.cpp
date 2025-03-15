/**
 * @see https://codeforces.com/contest/2044/problem/B
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == 'p') {
            std::cout << 'q';
        } else if(s[i] == 'q') {
            std::cout << 'p';
        } else {
            std::cout << s[i];
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}