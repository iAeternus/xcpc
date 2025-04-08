#include <bits/stdc++.h>

const int N = 1e5 + 3;
int n, c, a[N];

bool check(int mid) {
    int cnt = 1, cur = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i] - a[cur] >= mid) {
            ++cnt;
            cur = i;
        }
    }
    return cnt >= c;
}

int main() {
    std::cin >> n >> c;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);
    int l = 1, r = a[n] - a[1], ans;
    while(l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    std::cout << ans << std::endl;
}