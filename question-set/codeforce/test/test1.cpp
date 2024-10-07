#include <stdio.h>

typedef unsigned long long ull;

ull tenToTwoConvert(ull num) {
    ull result = 0;
    ull flag = 1;
    while(num) {
        result += (num % 2) * flag;
        flag *= 10;
        num >>= 1;
    }
    return result;
}

ull twoToTenConvert(ull num) {
    ull result = 0;
    ull flag = 1;
    while (num) {
        result += (num % 2) * flag;
        num >>= 1;
        flag <<= 1;
    }
    return result;
}

int main() {
    printf("%llu\n", tenToTwoConvert(1234));
    printf("%llu\n", twoToTenConvert(0b010011010010));
}