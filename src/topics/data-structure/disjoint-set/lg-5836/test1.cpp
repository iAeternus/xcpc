/**
 * @see https://www.luogu.com.cn/problem/P5836
 * 
 * 维护并查集，两节点连通且奶牛品种相同就合并
 * 要查询的两节点如果在同一个集合且集合的根不是喜欢的，就不会高兴
 * 否则就一定能喝到喜欢的
 */
#include <bits/stdc++.h>

const int N = 1e5 + 9;
int s[N]; // 集

void init() {
    for(int i = 1; i < N; ++i) {
        s[i] = i;
    }
}

int find(int x) {
    if(x == s[x]) {
        return x;
    }
    return s[x] = find(s[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    s[x] = y;
}

int main() {
    // freopen("P5836_2.in", "r", stdin);

    init();
    int n, m;
    scanf("%d %d", &n, &m);

    char species[N];
    scanf("%s", species + 1);

    for(int i = 1; i <= n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(species[x] == species[y]) {
            merge(x, y);
        }
    }

    while(m--) {
        int a, b;
        char c;
        scanf("%d %d %c", &a, &b, &c);

        if(find(a) == find(b) && species[a] != c) {
            putchar('0');
        } else {
            putchar('1');
        }
    }
}