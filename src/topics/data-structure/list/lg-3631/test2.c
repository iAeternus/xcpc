#include <stdio.h>

int next[1000003];

void insertAfter(int x, int y) {
    next[y] = next[x];
    next[x] = y;
}

void removeAfter(int x) {
    next[x] = next[next[x]];
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int op, x, y;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d %d", &x, &y);
            insertAfter(x, y);
        } else if(op == 2) {
            scanf("%d", &x);
            printf("%d\n", next[x]);
        } else {
            scanf("%d", &x);
            removeAfter(x);
        }
    }
}