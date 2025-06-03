#include <cassert>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
#include <bits/stdc++.h>

constexpr int INF = 1E7;

// 二分图最大权匹配
template <typename T>
struct MaxAssignment {
    // 计算最大权匹配
    T solve(int nx, int ny, std::vector<std::vector<T>> a) {
        assert(0 <= nx && nx <= ny);
        assert(int(a.size()) == nx);
        for (int i = 0; i < nx; ++i) {
            assert(int(a[i].size()) == ny);
            for (auto x : a[i])
                assert(x >= 0);
        }

        // 更新 slack 值和 slackx（记录达到最小 slack 的 x 索引）
        auto update = [&](int x) {
            for (int y = 0; y < ny; ++y) {
                if (lx[x] + ly[y] - a[x][y] < slack[y]) {
                    slack[y] = lx[x] + ly[y] - a[x][y];
                    slackx[y] = x;
                }
            }
        };

        // 初始化变量
        costs.resize(nx + 1); // 存储每一步的最大匹配权重
        costs[0] = 0;
        lx.assign(nx, std::numeric_limits<T>::max());        // 初始化 lx 为极大值
        ly.assign(ny, 0);                                    // 初始化 ly 为 0
        xy.assign(nx, -1);                                   // xy[x] 表示与 x 匹配的 y，初始化为 -1 表示未匹配
        yx.assign(ny, -1);                                   // yx[y] 表示与 y 匹配的 x，初始化为 -1 表示未匹配
        slackx.resize(ny);                                   // 存储每个 y 的最小 slack 对应的 x
        for (int cur = 0; cur < nx; ++cur) {                 // 对每一个 x 进行匹配
            std::queue<int> que;                             // 用于 BFS 的队列
            visx.assign(nx, false);                          // 记录 x 是否在 BFS 队列中
            visy.assign(ny, false);                          // 记录 y 是否在 BFS 队列中
            slack.assign(ny, std::numeric_limits<T>::max()); // 初始化 slack 为极大值
            p.assign(nx, -1);                                // 记录路径，p[x] 表示在增广路径中 x 的前一个顶点

            // 将所有未匹配的 x 加入队列
            for (int x = 0; x < nx; ++x) {
                if (xy[x] == -1) {
                    que.push(x);
                    visx[x] = true;
                    update(x); // 更新 slack
                }
            }

            int ex, ey;         // 记录找到的增广路径的起点和终点
            bool found = false; // 标记是否找到增广路径
            while (!found) {
                while (!que.empty() && !found) {
                    auto x = que.front();
                    que.pop();
                    for (int y = 0; y < ny; ++y) {
                        // 检查是否存在可行边 (x, y) 并且 y 未被访问
                        if (a[x][y] == lx[x] + ly[y] && !visy[y]) {
                            if (yx[y] == -1) { // 如果 y 未匹配，则找到增广路径
                                ex = x;
                                ey = y;
                                found = true;
                                break;
                            }
                            // 否则，继续 BFS，更新路径和 slack
                            que.push(yx[y]);
                            p[yx[y]] = x;
                            visy[y] = visx[yx[y]] = true;
                            update(yx[y]);
                        }
                    }
                }
                if (found)
                    break;

                // 未找到增广路径，修改标号以扩大可行边集合
                T delta = std::numeric_limits<T>::max();
                for (int y = 0; y < ny; ++y)
                    if (!visy[y])
                        delta = std::min(delta, slack[y]);
                for (int x = 0; x < nx; ++x)
                    if (visx[x])
                        lx[x] -= delta;
                for (int y = 0; y < ny; ++y) {
                    if (visy[y]) {
                        ly[y] += delta;
                    } else {
                        slack[y] -= delta;
                    }
                }
                // 检查是否可以通过修改后的 slack 找到增广路径
                for (int y = 0; y < ny; ++y) {
                    if (!visy[y] && slack[y] == 0) {
                        if (yx[y] == -1) {
                            ex = slackx[y];
                            ey = y;
                            found = true;
                            break;
                        }
                        que.push(yx[y]);
                        p[yx[y]] = slackx[y];
                        visy[y] = visx[yx[y]] = true;
                        update(yx[y]);
                    }
                }
            }

            // 更新最大匹配权重
            costs[cur + 1] = costs[cur];
            for (int x = ex, y = ey, ty; x != -1; x = p[x], y = ty) {
                costs[cur + 1] += a[x][y]; // 加入新匹配的权重
                if (xy[x] != -1)
                    costs[cur + 1] -= a[x][xy[x]]; // 减去之前匹配的权重
                ty = xy[x];
                xy[x] = y; // 更新匹配
                yx[y] = x;
            }
        }
        return costs[nx]; // 返回最大匹配权重
    }

    // 获取最终的匹配结果
    std::vector<int> assignment() {
        return xy;
    }

    // 获取最终的顶点标号
    std::pair<std::vector<T>, std::vector<T>> labels() {
        return std::make_pair(lx, ly);
    }

    // 获取每一步的最大匹配权重
    std::vector<T> weights() {
        return costs;
    }

    std::vector<T> lx, ly, slack, costs; // 分别存储 x 顶点、y 顶点的标号，slack 值和每一步的最大匹配权重
    std::vector<int> xy, yx, p, slackx;  // 分别存储匹配结果，路径记录和最小 slack 对应的 x
    std::vector<bool> visx, visy;        // 记录 BFS 过程中的访问状态
};

template <typename T>
void assertEquals(const std::vector<T>& v1, const std::vector<T>& v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < v1.size(); ++i) {
        assert(v1[i] == v2[i]);
    }
}

void should_assign() {
    // Given
    int nx = 3, ny = 3;
    std::vector<std::vector<int>> a = {
        {1, 2, 0},
        {0, 7, 3},
        {8, 0, 1},
    };

    // When
    MaxAssignment<int> ma;
    int cost = ma.solve(nx, ny, a);

    // Then
    assert(cost == 15);

    auto xy = ma.assignment();
    assert(int(xy.size()) == 3);
    assertEquals(xy, {2, 1, 0});

    auto [lx, ly] = ma.labels();
    assert(int(lx.size()) == 3);
    assert(int(ly.size()) == 3);
    assertEquals(lx, {0, 5, 7});
    assertEquals(ly, {1, 2, 0});

    auto weights = ma.weights();
    assert(weights[weights.size() - 1] == 15);
}

void should_assign_2() {
    // Given
    int nx = 1, ny = 1;
    std::vector<std::vector<int>> a = {
        {1},
    };

    // When
    MaxAssignment<int> ma;
    int cost = ma.solve(nx, ny, a);

    // Then
    assert(cost == 1);
}

int main() {
    should_assign();
    should_assign_2();
}