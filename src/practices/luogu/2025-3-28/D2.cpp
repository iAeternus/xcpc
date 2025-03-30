#include <bits/stdc++.h>
using namespace std;
long long a[1000003];
long long chafen[1000003];
struct cj {
    long long d, s, t;
} who[1000003];
int n, m;
int check(long long mid) {
    memset(chafen, 0, sizeof chafen);

    for (int i = 1; i <= n; i++) {
        chafen[i] += a[i];
        chafen[i + 1] -= a[i];
    }
    for (int i = 0; i < mid; i++) {
        chafen[who[i].s] -= who[i].d;
        chafen[who[i].t + 1] += who[i].d;
    }
    for (int i = 1; i <= n; i++) {
        chafen[i] += chafen[i - 1];
        if (chafen[i] < 0)
            return 0;
    }
    return 1;
}

int main() {
    int t;
    //cin>>t;
    t = 1;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            chafen[i] += a[i];
            chafen[i + 1] -= a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> who[i].d >> who[i].s >> who[i].t;
        }
        long long l, r, mid, ans;
        l = 0;
        r = m;
        while (l <= r) {
            mid = l + r >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        if (ans == m)
            cout << 0;
        else {
            cout << "-1" << endl
                 << ans + 1;
        }
    }
}