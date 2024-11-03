/*
0.01 -3.14

0.01 6.28
*/
#include <math.h>
#include <stdio.h>

double funcos(double e, double x);

int main() {
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

#define EPS 1e-8

bool equals(double x, double y) {
    return fabs(x - y) < EPS;
}

bool lt(double x, double y) {
    return y - x > EPS;
}

bool gt(double x, double y) {
    return x - y > EPS;
}

bool le(double x, double y) {
    return lt(x, y) || equals(x, y);
}

bool ge(double x, double y) {
    return gt(x, y) || equals(x, y);
}

double fact(int num) {
    if(num == 0) return 1.0;
    double ans = 1.0;
    for(int i = 2; i <= num; ++i) {
        ans *= i;
    }
    return ans;
}

double funcos(double e, double x) {
    int i = 0, j = 0;
    double item = 100000000000, ans = 0;
    while(gt(fabs(item), e)) {
        item = pow(x, i) / fact(i);
        ans = j & 1 ? ans - item : ans + item;
        i += 2;
        ++j;
    }
    return ans;
}