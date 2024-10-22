/**
 * https://www.luogu.com.cn/problem/P3382
 */
#include <bits/stdc++.h>

const int N = 15;
const double eps = 1e-6;
int n;
double nums[N];

double f(double x) {
    double s = 0;
    for (int i = n; i >= 0; --i) {
        s = s * x + nums[i];
    }
    return s;
}

double solve(double left, double right) {
    while (right - left > eps) {
        double k = (right - left) / 3.0;
        double mid1 = left + k, mid2 = right - k;
        if (f(mid1) > f(mid2)) {
            right = mid2;
        } else {
            left = mid1;
        }
    }
    return left;
}

int main() {
    double l, r;
    std::cin >> n >> l >> r;
    for (int i = n; i >= 0; --i) {
        std::cin >> nums[i];
    }

    std::cout << solve(l, r) << std::endl;
}