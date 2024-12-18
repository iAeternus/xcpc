/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=7433
 * TODO TLE!
 */
#include <bits/stdc++.h>

using i64 = unsigned long long;
std::set<i64> st;
constexpr int N = 2e6 + 5;
constexpr int B = 2333;
i64 pw[N];

void solve() {
    st.clear();
    std::string a, b;
    std::cin >> a >> b;
    int n = a.size();
    a = a + a;
    int m = b.size();
    a = ' ' + a, b = ' ' + b;
    int tmp = 0;
    for (int i = 1; i < n; i++) tmp = tmp * B + a[i] - 'A' + 1;
    for (int i = 1; i <= n; i++) {
        int t = i + n - 1;
        tmp = tmp * B + a[t] - 'A' + 1;
        st.insert(tmp);
        tmp -= pw[n - 1] * (a[i] - 'A' + 1);
    }
    tmp = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) tmp = tmp * B + b[i] - 'A' + 1;
    for (int i = 1; i + n - 1 <= m; i++) {
        int t = i + n - 1;
        tmp = tmp * B + b[t] - 'A' + 1;
        ans += st.count(tmp);
        tmp -= pw[n - 1] * (b[i] - 'A' + 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * B;
    }

    while (t--) {
        solve();
    }

    return 0;
}