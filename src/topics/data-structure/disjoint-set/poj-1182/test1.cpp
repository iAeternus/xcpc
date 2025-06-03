/**
 * @see http://poj.org/problem?id=1182
 * 
 * 卡常，司马了
 */
// #include <bits/stdc++.h>
#include <stdio.h>

const int N = 5e4 + 5;
int fa[N * 3];

void init(int n) {
    int tmp = n * 3;
    for (int i = 1; i <= tmp; ++i) {
        fa[i] = i;
    }
}

int find(int x) {
    int t = x;
    while (fa[t] != t) {
        t = fa[t];
    }
    while (x != t) {
        int tmp = fa[x];
        fa[x] = t;
        x = tmp;
    }
    return t;
}

void merge(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1 != r2) {
        fa[r1] = r2;
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int n, k;
    // std::cin >> n >> k;
    scanf("%d %d", &n, &k);
    init(n);
    int ans = 0;
    while (k--) {
        int d, x, y;
        // std::cin >> d >> x >> y;
        scanf("%d %d %d", &d, &x, &y);

        if (x < 1 || x > n || y < 1 || y > n) { // 不是这 n 种动物
            ++ans;
            continue;
        }

        if (d == 2 && x == y) { // xy相同
            ++ans;
            continue;
        }

        if (d == 1) {                                               // xy是同类
            if (find(x) == find(y + n) || find(x + n) == find(y)) { // xy是捕食或被捕食关系，假话
                ++ans;
                continue;
            }

            // 真话
            merge(x, y);                                        // x与y是同类
            merge(x + n, y + n);                                // x的猎物是y的猎物
            merge(x + 2 * n, y + 2 * n);                        // x的天敌是y的天敌
        } else if (d == 2) {                                    // x吃y
            if (find(x) == find(y) || find(x + n) == find(y)) { // xy是同类或被捕食关系，假话
                ++ans;
                continue;
            }

            // 真话
            merge(x, y + n);         // x的猎物是y的同类
            merge(x + n, y + 2 * n); // x的天敌是y的猎物
            merge(x + 2 * n, y);     // x的同类是y的天敌
        }
    }
    // std::cout << ans << "\n";
    printf("%d\n", ans);
}