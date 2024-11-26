#include <bits/stdc++.h>

const int N = 2e5 + 3;
std::map<int, int> mp;
std::vector<std::pair<int, int>> vec, tmp;
int fa[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    while (x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if (r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}

bool isF(int a) {
    return same(a, 0);
}

bool canSee(int a, int b) {
    return isF(a) && isF(b);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        mp.clear();
        vec.clear();
        tmp.clear();
        int n, m, k;
        std::cin >> n >> m >> k;
        init(k);
        for (int i = 1; i <= n; ++i) {
            int f;
            std::cin >> f;
            merge(0, f);
        }

        for (int i = 1; i <= k; ++i) {
            if (!isF(i)) {
                mp.insert({i, 0});
            }
        }

        bool tag = true;
        for(int i = 0; i < m; ++i) {
            int a, b;
            std::cin >> a >> b;
            vec.push_back({a, b});
            if (!canSee(a, b)) {
                tag = false;
                if (a == b) {
                    mp[a]++;
                    continue;
                }
                if (!isF(a)) {
                    mp[a]++;
                }
                if (!isF(b)) {
                    mp[b]++;
                }
            }
        }

        if (tag) {
            std::cout << m << std::endl;
            continue;
        }

        int firstMax = INT_MIN, secondMax = INT_MIN;
        int f1 = 0, f2 = 0;
        for (const auto& [i, cnt] : mp) {
            if (cnt > firstMax) {
                secondMax = firstMax;
                firstMax = cnt;
                f2 = f1;
                f1 = i;
            } else if (cnt > secondMax) {
                secondMax = cnt;
                f2 = i;
            }
        }

        if (f1) {
            merge(-1, f1);
        }
        if (f2) {
            merge(-1, f2);
        }

        int cnt = 0;
        for (const auto& [a, b] : vec) {
            if (canSee(a, b)) {
                ++cnt;
            }
        }
        std::cout << cnt << std::endl;
    }
}
