#include <bits/stdc++.h>
/*
4
21 10
jingicpcnanjingsuanan
21 0
jingicpcnanjingsuanan
21 3
nanjingnanjingnanjing
4 100
icpc
 */
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = min(k,n);
        string a;
        cin >> a;
        int i;
        string s;
        int aa = a.find("nanjing");
        if (aa > k||aa == std::string::npos) {
            string s1 = a.substr(0, k);
            string s2 = a.substr(k, a.size() - k);
            s = s2 + s1;
        } else {
            string s1 = a.substr(0, aa);
            string s2 = a.substr(aa, a.size() - aa);
            s = s2 + s1;
        }
        int ans = 0;
        while (1) {
            auto ttt = s.find("nanjing");
            if (ttt != string::npos) {
                s = s.substr(ttt + 7);
                ans++;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}
