#include <bits/stdc++.h>

int main() {
    double s, a, b;
    scanf("%lf %lf %lf", &s, &a, &b);
    double x = 2 * a * s / (3 * a + b);
    printf("%.06f\n", x / a + (s - x) / b);
}