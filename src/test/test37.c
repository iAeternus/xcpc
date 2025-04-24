#include <stdio.h>

void main() {
    int a[3][4], b[4][3], c[3][3] = {0}, i, j, k;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    for (j = 0; j < 4; j++)
        for (i = 0; i < 3; i++)
            scanf("%d", &b[j][i]);
    for (i = 0; i <= 2; i++)
        for (j = 0; j <= 2; j++)
            for (k = 0; k <= 3; k++)
                c[i][j] += a[i][k] * b[k][j];

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++)
            printf("%8d", c[i][j]);
        printf("\n");
    }
}