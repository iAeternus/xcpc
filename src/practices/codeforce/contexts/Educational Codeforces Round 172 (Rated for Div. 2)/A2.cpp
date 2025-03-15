#include <bits/stdc++.h>
using namespace std;
int a[52];
int cmp(int a, int b) {
    return a > b;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        long long kk = k;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n, cmp);
        int i = 0;
        while (k > 0) {
            if (i == n) {
                break;
            }
            k = k - a[i];
            i++;
        }
        if (k == 0) {
            cout << 0 << endl;
        }
        if (k < 0) {
            cout << k + a[i - 1] << endl;
            continue;
        }
        if (k > 0) {
            cout << kk - sum << endl;
            continue;
        }
    }
}