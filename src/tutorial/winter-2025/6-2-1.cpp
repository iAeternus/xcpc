#include <bits/stdc++.h>

int n, r;

void solve() {
    std::vector<int> path;
    std::function<void(int)> dfs = [&](int depth) {
        if (path.size() == r) {
            for (const auto& it : path) {
                std::cout << std::setw(3) << it;
            }
            std::cout << std::endl;
            return;
        }
        for (int i = depth; i <= n; ++i) {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    };
    dfs(1);
}

int main() {
    std::cin >> n >> r;
    solve();
}