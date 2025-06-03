/**
 * https://www.luogu.com.cn/problem/P4155
 */
#include <bits/stdc++.h>

const int N = 4e5 + 3;
int n, m;

struct warrior {
    int id, l, r;

    bool operator<(const warrior& other) {
        return this->l < other.l;
    }
} w[N << 1];

int n1;
// go[s][i]: 从第s个区间出发，走2^i个最优区间后到达的区间
int go[N][20];

/**
 * 贪心 + 预计算倍增
 */
void init() {
    int next = 1;
    for (int i = 1; i <= n1; ++i) {
        while (next <= n1 && w[next].l <= w[i].r) {
            ++next;
        }
        go[i][0] = next - 1;
    }

    for (int i = 1; (1 << i) <= n; ++i) {
        for (int s = 1; s <= n1; ++s) {
            go[s][i] = go[go[s][i - 1]][i - 1];
        }
    }
}

int res[N];

void get_ans(int x) {
    int len = w[x].l + m, cur = x, ans = 1;
    for (int i = log2(N); i >= 0; --i) {
        int pos = go[cur][i];
        if (pos && w[pos].r < len) {
            ans += 1 << i;
            cur = pos;
        }
    }
    res[w[x].id] = ans + 1;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        w[i].id = i;
        std::cin >> w[i].l >> w[i].r;
        // 把环变成链
        if (w[i].r < w[i].l) {
            w[i].r += m;
        }
    }
    std::sort(w + 1, w + n + 1);
    n1 = n;
    // 拆环加倍成一条链
    for (int i = 1; i <= n; ++i) {
        ++n1;
        w[n1] = w[i];
        w[n1].l = w[i].l + m;
        w[n1].r = w[i].r + m;
    }

    init();

    // 逐个计算每个战士
    for (int i = 1; i <= n; ++i) {
        get_ans(i);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << ' ';
    }
}