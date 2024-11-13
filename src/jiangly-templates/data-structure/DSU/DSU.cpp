/**
 * @brief 并查集 DSU
 * @author Ricky
 * @date 2024/11/9
 * @version 1.0
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

void basic_test() {
    int n = 10;
    DSU d(n);

    // [0, 1, 2, 3] [4, 5] [6] [7, 8, 9]
    d.merge(0, 1), d.merge(0, 2), d.merge(0, 3);
    d.merge(4, 5);
    d.merge(7, 8), d.merge(7, 9);

    assert(d.same(1, 2) == true);
    assert(d.same(1, 4) == false);
    assert(d.same(6, 7) == false);
    assert(d.size(2) == 4);
    assert(d.size(6) == 1);
    assert(d.count() == 4);
}

int main() {
    basic_test();
}