/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=7433
 * TODO TLE!
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    int cnt = 0;
    do {
        int pos = 0;
        while ((pos = b.find(a, pos)) != std::string::npos) {
            ++cnt;
            pos += a.length();
        }
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << cnt << std::endl;
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