#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int max_cnt = 0, cnt = 0, idx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++cnt;
        } else {
            max_cnt = std::max(max_cnt, cnt);
            idx = i;
            cnt = 0;
        }
    }

    // TODO

    if (idx == 0) {
        std::reverse(s.begin(), s.end());
    } else {
        int jdx = -1;
        for (int i = idx - 1; i >= 0; --i) {
            if (s[i] == '0') {
                jdx = i;
            }
        }
        std::reverse(s.begin(), s.begin() + jdx + 1);
    }

    int ans = s.length();
    std::string ss = "0" + s;
    for (int i = 1; i < ss.length(); ++i) {
        if (ss[i] != ss[i - 1]) {
            ans++;
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