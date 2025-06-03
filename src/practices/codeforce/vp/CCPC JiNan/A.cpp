#include <bits/stdc++.h>
using namespace std;
vector<string> a;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    string s1, s2, s3;
    for (int i = 0; i < k; i++) {
        s1 += a[0][i];
        s3 += a[1][i];
    }
    for (int i = k; i < 2 * k; i++) {
        s2 += a[0][i];
    }
    string ans;
    if (s1 == s2) {
        if (s1 == s3) {
            ans = s1;
        } else {
            cout << 2 << " " << 1;
            return 0;
        }
        // return 0;
    } else {
        if (s1 == s3) {
            cout << "1 2";
        } else {
            cout << "1 1";
        }
        return 0;
    }
    int j = 0;
    int aa = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string tt;
            for (int jj = j * k; jj < (j + 1) * k; jj++) {
                tt.push_back(a[i][jj]);
            }
            if (tt == ans)
                continue;
            else {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}
