/**
 * @see https://codeforces.com/problemset/problem/2027/B?locale=en
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans = n;
    std::priority_queue<int> le;
    std::priority_queue<int, std::vector<int>, std::greater<>> ge;

    for(int i = n - 1; i >= 0; --i) {
        while(!ge.empty() && ge.top() <= a[i]) {
            le.push(ge.top());
            ge.pop();
        }
        while(!le.empty() && le.top() > a[i]) {
            ge.push(le.top());
            le.pop();
        }
        ans = std::min(ans, (i - 1) + int(ge.size()));
        ge.push(a[i]);
    }
    std::cout << ans << std::endl;
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