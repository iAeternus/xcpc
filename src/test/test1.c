#include <stdio.h>

int main() {
    int a[5][5];
    int (*p)[4];
    p = (int(*)[4]) a;
    printf("%p %p\n", a[0], p[0]);
    printf("%p %p\n", a[1], p[1]);
    printf("%p %p\n", a[2], p[2]);
    printf("%p %d\n", &a[4][2] - &p[4][2], &a[4][2] - &p[4][2]);
}