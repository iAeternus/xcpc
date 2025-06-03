/**
 * AC
 */
#include <bits/stdc++.h>

const int N = 2e5 + 7;
int n, m, k, w;
int tot;
std::pair<int, int> a[N]; // key-索引 val-0红 1黑

std::vector<int> ans, f;

void solve() {
    tot = 0;
    ans.clear();

    std::cin >> n >> m >> k >> w;
    a[++tot] = {0, 1};
    int x;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        a[++tot] = {x, 0};
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> x;
        a[++tot] = {x, 1};
    }
    a[++tot] = {w + 1, 1}; // 虚拟黑右边界
    std::sort(a + 1, a + 1 + tot);
    int l = 1;
    for (int i = 2; i <= tot; ++i) { // 遍历黑的
        if (a[i].second == 1) {
            if (i != l + 1) { // 不是连续两个黑的
                f.clear();
                for (int j = l + 1; j <= i - 1; ++j) {
                    int tmp = a[j].first;
                    f.push_back(tmp);
                    while (j + 1 <= i && tmp + k - 1 >= a[j + 1].first) {
                        // 这个还覆盖了别的
                        ++j;
                    }
                    if (j == i) {
                        int len = tmp + k - a[j].first;
                        int idx = f.size() - 1;
                        while (len > 0 && len) {
                            if (idx == 0) {
                                f[idx] -= len;
                                break;
                            } else {
                                f[idx] -= len;
                                len = std::max(0, f[idx - 1] + k - f[idx]);
                            }
                            idx--;
                        }
                    }
                }
                if (f[0] <= a[l].first) {
                    std::cout << -1 << std::endl;
                    return;
                }
                for (const auto& it : f) {
                    ans.push_back(it);
                }
            }
            l = i; // 维护左边界
        }
    }
    std::cout << ans.size() << std::endl;
    for (const auto& it : ans) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}