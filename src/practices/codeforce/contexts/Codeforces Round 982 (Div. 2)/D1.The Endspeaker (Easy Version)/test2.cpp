#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long a[300003];
long long b[300003];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> ans(n + 1, 0);
        vector<long long> dp(n + 1, 1e18);
        int i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            ans[i + 1] = ans[i] + a[i];
        }
        
        dp[0] = 0;
        for (int k = 1; k <= m; k++) {
            long long bns = b[k - 1];
            for (int i = 0; i < n; i++) {
                long long sum = ans[i] + bns;
                if (dp[i] == 1e18)
                    continue;
                long long j = upper_bound(ans.begin(), ans.end(), sum) - ans.begin() - 1;
                if (j >= i + 1 && j <= n) {
                    dp[j] = min(dp[j], dp[i] + 1ll * m - k);
                }
            }
        }
        if (dp[n] == 1e18)
            cout << -1 << endl;
        else
            cout << dp[n] << endl;
    }
    return 0;
}