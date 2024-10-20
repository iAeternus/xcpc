#include <bits/stdc++.h>
using namespace std;
int a[103][103];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int i, j;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int fmax = 0;
        int c, d;
        int ans = 0;
        int bns = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                for (c = i - 1; c <= i + 1; c++) {
                    for (d = j - 1; d <= j + 1; d++) {
                        if (abs(i - c) + abs(j - d) == 1) {
                            if (d < 1 || c < 1 || d > m || c > n)
                                continue;
                            if (a[i][j] > a[c][d]) {
                                fmax = max(fmax, a[c][d]);
                                ans = 1;
                            } else {
                                bns = 1;
                                break;
                            }
                        }
                    }
                }
                if (bns == 1) {
                    bns = 0;
                    continue;
                }
                if (ans == 1) {
                    a[i][j] = fmax;
                    fmax = 0;
                    ans = 0;
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}