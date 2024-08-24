/**
 * 对于4个任意有理数a,b,c,d, 始终有 a = b^3 + c^3 + d^3
 */
#include <bits/stdc++.h>

void split(double a, double& b, double& c, double& d) {
    b = (a - 9) / 9;
    double tmp = 729 + 81 * a - 9 * a * a;
    c = (729 + 243 * a - a * a * a) / tmp;
    d = (243 * a + 27 * a * a) / tmp;
}

int main() {
    double a = 1;
    for(int i = 0; i < 100; ++i) {

        double b, c, d;
        split(a, b, c, d);

        double pow3_b = b * b * b;
        double pow3_c = c * c * c;
        double pow3_d = d * d * d;
        double total = pow3_b + pow3_c + pow3_d;

        printf("%g = %g^3 + %g^3 + %g^3 = %g + %g + %g = %g\n", a, b, c, d, pow3_b, pow3_c, pow3_d, total);

        a++;
    }
}