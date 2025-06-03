#include <bits/stdc++.h>

const int N = 1e5 + 3;
int n, k;
int h[N], w[N];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (h[i] / x) * (w[i] / x);
    }
    return cnt >= k;
}

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i] >> w[i];
    }

    int l = 1, r = 1e5;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << std::endl;
}