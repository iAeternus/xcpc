#include <stdio.h>
#include <stdlib.h>

void func(int** a, int n, int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int n = 5, m = 3;
    int** a = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < n; ++i) {
        a[i] = (int*)malloc(sizeof(int) * m);
    }

    func(a, n, m);

    for(int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
}