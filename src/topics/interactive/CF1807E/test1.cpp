/**
 * @see https://www.luogu.com.cn/problem/CF1807E
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 3;
int n, a[N], pre[N];

int ask(int l, int r) {
    std::cout << "? " << r - l + 1 << ' ';
    for (int i = l; i <= r; ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout.flush();
    int x;
    std::cin >> x;
    return x;
}

void ret(int x) {
    std::cout << "! " << x << std::endl;
}

bool check(int l, int mid) {
    return ask(l, mid) != pre[mid] - pre[l - 1];
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(l, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ret(l);
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