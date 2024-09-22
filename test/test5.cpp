/*
7
1000 F
1000 F
1000 F
1000 F
1000 B
1000 B
1000 B
*/
#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<int, std::pair<int, int>> mp;  // 钱 -> (前端数量, 后端数量)

    for (int i = 0; i < N; ++i) {
        int s;
        char p;
        std::cin >> s >> p;

        if (p == 'F') {
            mp[s].first++;
        } else {
            mp[s].second++;
        }
    }

    int cnt = 0;

    for (const auto& [s, c] : mp) {
        int F = c.first;
        int B = c.second;

        int groups = std::min(F, B);
        cnt += groups;
    }

    std::cout << cnt << std::endl;

    return 0;
}