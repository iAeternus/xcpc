#include <bits/stdc++.h>

const int N = 1e4 + 3;
bool vis[N];

int main() {
    int l, m;
    std::cin >> l >> m;
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        for (int i = u; i <= v; ++i) {
            vis[i] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; ++i) {
        ans += !vis[i];
    }
    std::cout << ans << std::endl;
}