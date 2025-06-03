#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string res, tmp;
    for (int i = 0; i < n; ++i) {
        tmp = s;
        if (s[i] == '0') {
            tmp[i] = '1';
        } else {
            tmp[i] = '0';
        }
        res += tmp;
    }
    int ans = 0;
    for (int i = 0; i < res.length(); ++i) {
        if (res[i] == '1') {
            ++ans;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}