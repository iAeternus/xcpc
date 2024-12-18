#include <bits/stdc++.h>
using namespace std;
int ans[100003];
int bns[100003];
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        memset(bns, 0, sizeof(bns));
        int n, d, k;
        // scanf("%d %d %d", &n, &d, &k);
        std::cin >> n >> d >> k;
        for (int i = 0; i < k; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            ans[l]++;
            bns[r]++;
        }
        for (int i = 0; i < n; i++) {
            ans[i + 1] += ans[i];
            bns[i + 1] += bns[i];
        }
        int fmax, fmin;
        fmax = 0;
        fmin = 1e9;
        int a, b;
        a = b = 0;
        for (int i = d; i <= n; i++) {
            int tt = ans[i] - bns[i - d];
            if (tt > fmax) {
                fmax = tt;
                a = i - d + 1;
            }
            if (tt < fmin) {
                fmin = tt;
                b = i - d + 1;
            }
        }
        printf("%lld %lld\n", a, b);
        //cout<<a<<" "<<b<<endl;
    }
}