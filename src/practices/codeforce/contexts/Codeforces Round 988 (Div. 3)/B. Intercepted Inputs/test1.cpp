/**
 * @see https://codeforces.com/contest/2037/problem/B
 */
#include <bits/stdc++.h>

const int N = 2e5 + 3;
int a[N];

int fix(int m, int k) {
    if ((k - 2) % m != 0) {
        return (k - 2) / m + 1;
    } else {
        return (k - 2) / m;
    }
}

int main() {
    int t;
    std::cin >> t;
    std::multimap<int, int> mp;
    int ans_n, ans_m;
    while (t--) {
        mp.clear();
        int k;
        std::cin >> k;
        // for(int i = 0; i < k; ++i) {
        //     int a;
        //     std::cin >> a;
        //     // mp[a] = (k - 2) / a;
        //     mp.insert({a, (k - 2) / a});
        // }

        // for(const auto&[m, n] : mp) {
        //     if(mp.contains((k - 2) / m)) {
        //         std::cout << mp.find((k - 2) / m)->second << ' ' << m << std::endl;
        //         break;
        //     }
        // }

        for (int i = 0; i < k; ++i) {
            int m;
            std::cin >> m;
            a[i] = m;
            // auto it = mp.find(fix(m, k));
            // if(it != mp.end()) {
            //     ans_n = mp.find(m)->second;
            //     ans_m = m;
            // }
            mp.insert({m, fix(m, k)});
        }

        bool tag = false;
        for (const auto& [m, n] : mp) {
            if (mp.find(fix(m, k)) != mp.end()) {
                std::cout << mp.find(m)->second << ' ' << m << std::endl;
                tag = true;
                break;
            }
        }

        if (!tag) {
            std::cout << a[0] << ' ' << a[1] << std::endl;
        }
    }
}