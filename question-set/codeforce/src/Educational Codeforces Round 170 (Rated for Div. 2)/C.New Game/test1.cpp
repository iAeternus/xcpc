/**
 * @see https://codeforces.com/contest/2025/problem/C
 */
#include <bits/stdc++.h>

std::map<int, int> mp;

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        mp.clear();
        int n, k;
        std::cin >> n >> k;

        for(int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            if(mp.count(num) == 0) {
                mp.insert({num, 1});
            } else {
                mp[num]++;
            }
        }

        std::vector<std::pair<int, int>> vec(mp.begin(), mp.end());
        std::sort(vec.begin(), vec.end(), [](auto a, auto b) -> bool {
            return a.second > b.second;
        });

        int ans = 0;
        for(int i = 0; i < k; ++i) {
            auto[num, cnt] = vec[i];
            ans += cnt;
        }

        std::cout << ans << std::endl;
    }
}