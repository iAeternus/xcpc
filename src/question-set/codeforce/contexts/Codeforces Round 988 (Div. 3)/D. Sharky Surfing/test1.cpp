#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
int main() {
    int t;
    cin >> t;
    while (t--) {
        priority_queue<long long> qe;
        mp.clear();
        int n, m, l;
        cin >> n >> m >> l;
        for (int i = 0; i < n; i++) {
            int tt, ttt;
            cin >> tt >> ttt;
            mp[tt] = ttt - tt + 2;
        }
        auto it = mp.begin();
        long long ans = 1;
        int finish = 0;
        int cishu = 0;
        int bns = 0;
        for (int i = 0; i < m; i++) {
            long long tt, ttt;
            cin >> tt >> ttt;
            if (bns == 1) {
                continue;
            }
            if (it == mp.end())
                continue;
            if (tt < it->first) {
                qe.push(ttt);
            } else {
                while (tt > it->first) {
                    while (ans < it->second) {
                        if (qe.empty()) {
                            bns = 1;
                            break;
                        }
                        cishu++;
                        ans += qe.top();
                        qe.pop();
                    }
                    if (bns == 1)
                        break;
                    finish++;
                    it++;
                    if (it == mp.end())
                        break;
                }
                qe.push(ttt);
            }
        }
        while (finish < n) {
            while (ans < it->second) {
                if (qe.empty()) {
                    bns = 1;
                    break;
                }
                cishu++;
                ans += qe.top();
                qe.pop();
            }
            it++;
            if (bns == 1)
                break;
            finish++;
        }
        if (bns == 1) {
            cout << -1 << endl;
        } else {
            cout << cishu << endl;
        }
    }
}
