#include <bits/stdc++.h>

int n, m;
std::vector<char> v;

void dfs(int idx) {
    if (v.size() == m) {
        for (int i = 0; i < v.size(); ++i) {
            std::cout << v[i];
        }
        std::cout << std::endl;
        return;
    }
    for (int i = idx; i < n; ++i) {
        v.push_back(i + 'A');
        dfs(i + 1);
        v.pop_back();
    }
}

int main() {
    std::cin >> n >> m;
    dfs(0);
}