#include <bits/stdc++.h>
using namespace std;
int a[200003];
int main() {
    int t;
    cin >> t;
    while (t--) {
        set<int> st;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tt;
            cin >> tt;
            st.insert(tt);
        }
        n = n - 2;
        int x, y;
        for (auto& it : st) {
            int ttt;
            if (n % it == 0) {
                ttt = n / it;
                auto ii = st.find(ttt);
                if (ii == st.end()) {
                } else {
                    x = ttt;
                    y = it;
                    break;
                }
            }
        }
        cout << x << " " << y << endl;
    }
}