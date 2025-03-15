/**
 * @see https://codeforces.com/contest/2042/problem/B
 */
#include <bits/stdc++.h>

std::unordered_map<int, int> mp;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        mp.clear();
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            int c;
            std::cin >> c;
            mp[c]++;
        }
        int cnt_one = 0, cnt_other = 0;
        for(const auto&[num, cnt] : mp) {
            if(cnt == 1) {
                cnt_one++;
            } else {
                cnt_other++;
            }
        }
        std::cout << ((cnt_one + 1) >> 1) * 2 + cnt_other << std::endl;
    }   
}