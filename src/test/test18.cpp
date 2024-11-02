#include <stdio.h>

int main() {
    freopen("1.in", "r", stdin);

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }

    for(int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}