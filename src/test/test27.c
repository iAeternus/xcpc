#include <stdio.h>

int n, k;
int parts[1005], size;

void dfs(int start, int sum, int prev) {
    if(size == k) {
        if(sum == n) {
            for (int i = 0; i < size; ++i) {
                printf("%d ", parts[i]);
            }
            putchar('\n');
        }
        return;
    }
    for(int i = prev; i <= n - sum; ++i) {
        parts[size++] = i;
        dfs(i + 1, sum + i, i);
        size--;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    dfs(1, 0, 1);
}