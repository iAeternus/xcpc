/**
 * @see https://codeforces.com/contest/2037/problem/0
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    std::unordered_map<int, int> mp;
    while(t--) {
        mp.clear();
        int n;
        std::cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            mp[a]++;
            if(mp[a] == 2) {
                mp.erase(a);
                ++cnt;
            }
        }
        std::cout << cnt << std::endl;
    }
}