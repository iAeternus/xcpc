#include <bits/stdc++.h>

using i64 = long long;

bool has_eq(const std::string& s) {
    for(int i = 1; i < s.length(); ++i) {
        if(s[i] == s[i - 1]) {
            return true;
        }
    }
    return false;
}

void solve() {
    std::string s;
    std::cin >> s;
    std::cout << (has_eq(s) ? 1 : s.length()) << std::endl;
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