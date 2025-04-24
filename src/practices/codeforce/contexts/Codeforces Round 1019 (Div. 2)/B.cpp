#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l, r;
        l = r = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                l = i;
                break;
            }
        }
        int bns = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                bns = 1;
                r = i;
                //break;
            } else { //0000111000
                if (bns == 1) {
                    r--;
                    break;
                }
            }
        }

        if (l < r) {
            reverse(s.begin() + l, s.begin() + r + 1);
        } else {
            reverse(s.begin() + l, s.end());
        }
        int cns = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' == cns) {
                sum2++;
            } else {
                sum2 += 2;
                cns = !cns;
            }
        }
        cout << sum2 << endl;
    }
}