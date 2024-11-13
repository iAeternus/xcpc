/**
 * @see https://www.luogu.com.cn/problem/P1892
 */
#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;

    DSU() {}

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    /**
     * @brief 查找 x 所在集合的队长
     */
    int find(int x) {
        while(x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    /**
     * @brief 判断 x 和 y 是否属于同一个集合
     */
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    /**
     * @brief 将 x 和 y 合并为同一个集合
     * @return true=合并成功 false=x 和 y 本来就在同一个集合
     */
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    /**
     * @brief 获取 x 所在集合的大小
     */
    int size(int x) {
        return siz[find(x)];
    }

    /**
     * @brief 获取一共能组成多少个集合
     */
    int count() {
        int cnt = 0;
        for(int i = 0; i < f.size(); ++i) {
            if(i == f[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};

const int N = 1e3 + 5;
int e[N];

int main() {
    int n, m;
    std::cin >> n >> m;
    DSU d(n + 1);
    while(m--) {
        char opt;
        int p, q;
        std::cin >> opt >> p >> q;
        p--, q--;
        if(opt == 'F') {
            d.merge(p, q);
        } else {
            if(!e[p]) {
                e[p] = d.find(q);
            } else {
                d.merge(q, e[p]);
            }

            if(!e[q]) {
                e[q] = d.find(p);
            } else {
                d.merge(p, e[q]);
            }
        }
    }

    std::cout << d.count() << std::endl;
}
