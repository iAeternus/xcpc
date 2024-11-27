#include <bits/stdc++.h>

int main() {
    int n = 10;
    int a[n] = {1, 5, 5, 5, 4, 4, 4, 4, 2, 3};

    std::map<int, int> mp; // k-num v-cnt
    for(int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }

    for(const auto& [num, cnt] : mp) {
        std::cout << num << ':' << cnt << std::endl;
    }
}