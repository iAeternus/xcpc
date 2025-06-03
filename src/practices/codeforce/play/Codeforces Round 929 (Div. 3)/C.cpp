/**
 * @see https://codeforces.com/contest/1933/problem/C
 * l = k * a^x * b^y
 * 注意到只有a|l && b|l时条件成立，枚举x y即可
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, l;
    std::cin >> a >> b >> l;
    std::set<int> s;
    int ans = 0;
    while (true) {
        int tmp = l;
        while (true) {
            s.insert(tmp);
            if (tmp % b != 0) {
                break;
            }
            tmp /= b;
        }
        if (l % a != 0) {
            break;
        }
        l /= a;
    }
    std::cout << s.size() << std::endl;
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