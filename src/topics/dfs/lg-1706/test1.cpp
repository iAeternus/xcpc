/**
 * @see https://www.luogu.com.cn/problem/P1706
 */
#include <bits/stdc++.h>

int n;

void solve() {
    std::vector<bool> vis(n, false);
    std::vector<int> path;
    std::function<void(int)> dfs = [&](int depth) {
        if (depth == n) {
            for (const auto& num : path) {
                std::cout << std::setw(5) << num;
            }
            std::cout << std::endl;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                path.push_back(i);
                vis[i] = true;
                dfs(depth + 1);
                path.pop_back();
                vis[i] = false;
            }
        }
    };
    dfs(0);
}

int main() {
    std::cin >> n;
    solve();
}