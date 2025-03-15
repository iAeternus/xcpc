/*
https://codeforces.com/contest/1986/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
int ind[100003];
char c[100003];
string s;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cin >> s;
        int i;
        for (i = 0; i < m; i++) {
            cin >> ind[i];
        }
        sort(ind, ind + m);
        for (i = 0; i < m; i++) {
            cin >> c[i];
        }
        sort(c, c + m);
        int tt = 0;
        s[ind[0] - 1] = c[tt];
        tt++;
        for (i = 1; i < m; i++) {
            if (ind[i - 1] != ind[i]) {
                s[ind[i] - 1] = c[tt++];
            }
        }
        cout << s << endl;
    }

    return 0;
}