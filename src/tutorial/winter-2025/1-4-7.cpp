#include <bits/stdc++.h>

int main() {
    int n = 10;
    int a[] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 4};

    std::unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }

    for(const auto&[num, count] : mp) {
        std::cout << num << ' ' << count << std::endl;
    }

    std::stack<int> st;
    std::queue<int> q;
}