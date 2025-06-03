#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> v(n);
    int min_ = INT_MAX;
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i].first;
    }
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i].second;
        min_ = std::min(min_, v[i].second - v[i].first);
    }

    if(k < min_) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        return o1.first < o2.first;
    });


    int ans = 1;
    for(int i = 1; i < v.size(); ++i) {
        
    }
}