/**
 * @see http://poj.org/problem?id=1265
 *
 * Pick定理：
 * 一个计算点阵中顶点在格点上的多边形面积公式：S = a + b / 2 - 1，其中a表示多边形内部的点数，b表示多边形边界上的点数，S表示多边形的面积
 */
#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int cross_mul(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    int t, times = 0;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int area = 0;
        // (x, y)起始点
        int x = 0, y = 0, dx = 0, dy = 0;
        int ans2 = 0;
        for (int i = 1; i <= n; ++i) {
            int tx, ty;
            std::cin >> tx >> ty; // x和y的变化量

            // 新点坐标
            dx = x + tx;
            dy = y + ty;
            ans2 += gcd(abs(tx), abs(ty));   // 求出边上点的数量
            area += cross_mul(x, y, dx, dy); // 旧点坐标和新点坐标，也是原点到这两点的向量

            x = dx;
            y = dy;
        }

        area = abs(area);
        double ans3 = (double)area / 2;
        int ans1 = (area + 2 - ans2) / 2;
        std::cout << "Scenario #" << ++times << ":\n"
                  << ans1 << "  " << ans2 << "  " << std::fixed << std::setprecision(1) << ans3 << std::endl
                  << std::endl;
    }
}