/**
 * @see https://www.luogu.com.cn/problem/P1196
 */
#include <bits/stdc++.h>

const int N = 3e5 + 7;
int fa[N], dis[N];
int cnt[N]; // 编号为 i 的那一列有 cnt[i] 艘战舰

int query(int x) {
    if (x != fa[x]) {
        int k = fa[x];
        fa[x] = query(fa[x]);
        dis[x] += dis[k];
        cnt[x] = cnt[fa[x]];
    }
    return fa[x];
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if (r1 != r2) {
        fa[r1] = r2;
        dis[r1] = dis[r2] + cnt[r2];
        cnt[r2] += cnt[r1];
        cnt[r1] = cnt[r2];
    }
}

int same(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    return r1 != r2 ? -1 : abs(dis[x] - dis[y]) - 1;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        char op;
        int i, j;
        std::cin >> op >> i >> j;
        if (op == 'M') {
            merge(i, j);
        } else {
            std::cout << same(i, j) << std::endl;
        }
    }
}