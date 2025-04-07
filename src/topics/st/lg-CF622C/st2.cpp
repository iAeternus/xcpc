#include <bits/stdc++.h>

template <typename T>
struct St {
    int n;
    std::vector<T> a;                 // 下标从1开始
    std::vector<std::vector<T>> st;   // ST表
    const std::function<T(T, T)> cmp; // 比较规则

    St(int n, const std::vector<T>& _a, std::function<T(T, T)> _cmp) :
            n(n), a(_a), cmp(_cmp) {
        assert(a.size() > n);

        const int LG = std::__lg(n);
        st.assign(LG + 1, std::vector<T>(n + 1));

        for (int i = 1; i <= n; i++) {
            st[0][i] = i;
        }

        for (int j = 1; j <= LG; j++) {
            for (int i = 1; i <= n - (1 << j) + 1; i++) {
                st[j][i] = cmp(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
            }
        }
    }

    /**
     * 区间查询
     */
    T query(int l, int r) {
        int k = std::__lg(r - l + 1);
        return cmp(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto rmqMin = St<int>(n, a, [&](int i, int j) {
        return a[i] < a[j] ? i : j;
    });
    auto rmqMax = St<int>(n, a, [&](int i, int j) {
        return a[i] > a[j] ? i : j;
    });

    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;

        int minidx = rmqMin.query(l, r), maxidx = rmqMax.query(l, r);
        if (a[minidx] == a[maxidx] && a[minidx] == x) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << (a[minidx] != x ? minidx : maxidx) << std::endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}