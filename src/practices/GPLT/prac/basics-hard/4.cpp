/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582339&page=0
 */
#include <bits/stdc++.h>

using i64 = long long;

struct Frac {
    i64 x, y;
};

i64 gcd(i64 a, i64 b) {
    return b ? gcd(b, a % b) : a;
}

i64 lcm(i64 a, i64 b) {
    return b / gcd(a, b) * a;
}

void norm(i64& x, i64& y) {
    i64 g = gcd(x, y);
    x /= g;
    y /= g;
}

void add(Frac& f1, const Frac& f2) {
    i64 nx = f1.x * f2.y + f1.y * f2.x;
    i64 ny = f1.y * f2.y;
    norm(nx, ny);
    f1 = {nx, ny};
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Frac> fs;
    Frac f{0, 1};
    while(n--) {
        i64 x, y;
        scanf("%lld/%lld", &x, &y);
        norm(x, y);
        add(f, Frac{x, y});
    }
    if(f.x % f.y == 0) {
        printf("%lld", f.x / f.y);
    } else if(f.x < f.y) {
        printf("%lld/%lld", f.x, f.y);
    } else {
        printf("%lld %lld/%lld", f.x / f.y, f.x % f.y, f.y);
    }
}