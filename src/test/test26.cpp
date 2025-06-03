#include <bits/stdc++.h>

void solve(int n, int k) {
    std::vector<int> parts;
    std::vector<std::vector<int>> allParts;
    std::function<void(int, int, int)> dfs = [&](int start, int sum, int prev) {
        if (parts.size() == k && sum == n) {
            allParts.push_back(parts);
            return;
        }

        for (int i = (prev == 0 ? 1 : prev); i <= n - sum; ++i) {
            parts.push_back(i);
            dfs(i + 1, sum + i, i);
            parts.pop_back();
        }
    };
    dfs(1, 0, 0);
    for (const auto& parts : allParts) {
        for (const auto& part : parts) {
            std::cout << part << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    solve(n, k);
}