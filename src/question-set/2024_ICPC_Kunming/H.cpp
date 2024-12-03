#include <bits/stdc++.h>

struct Island {
    int x, y;
    double alpha;
};

struct Cmp {
    bool operator()(const Island& o1, const Island& o2) const {
        return o1.alpha < o2.alpha;
    }
};

std::set<Island, Cmp> islands;
std::vector<double> durations;

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            int x, y;
            std::cin >> x >> y;
            islands.insert({x, y, atan2(y, x)});
        }
        for(auto it = std::next(islands.begin()); it != islands.end(); ++it) {
            durations.push_back(it->alpha - std::prev(it)->alpha);
        }

        if(durations.empty()) {
            std::cout << "6.2831853072\n";
            continue;
        }

        int cnt = 0;
        double ans = 0, max_ans = 0;
        for(const auto& it : durations) {
            if(cnt < k) {
                ans += it;
                cnt++;
            } else {
                max_ans = std::max(max_ans, ans);
                ans = 0;
                cnt = 0;
            }
        }
        std::cout << max_ans << std::endl;

        // int cnt = 0;
        // double ans = 0.0, max_ans = 0.0;
        // for(const auto& island : islands) {
        //     ans += island.alpha;
        //     max_ans = std::max(max_ans, ans);
        //     ++cnt;
        //     if(cnt == k + 1) {
        //         cnt = 0;
        //         ans = 0.0;
        //     }
        // }
        // std::cout << max_ans << std::endl;
    }
}