#include <bits/stdc++.h>

int dayOfMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main() {
    int a, b, c;
    scanf("%02d/%02d/%02d", &a, &b, &c);

    for(int y = 1960; y <= 2059; ++y) {
        dayOfMonth[2] = isLeapYear(y) ? 29 : 28;
        for(int m = 1; m <= 12; ++m) {
            for(int d = 1; d <= dayOfMonth[m]; ++d) {
                int sy = y % 100;
                if(a == sy && b == m && c == d || c == sy && a == m && b == d || c == sy && b == m && a == d) {
                    printf("%d-%02d-%02d\n", y, m, d);
                }
            }
        }
    }
}