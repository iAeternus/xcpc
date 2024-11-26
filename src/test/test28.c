#include <stdio.h>

int n, k;
int cnt;

void dfs(int start, int sum, int prev) {
    if (start == k) {
        if (sum == n) ++cnt;
        return;
    }
    for (int i = prev; i * (k - start) <= n - sum; ++i) {
        dfs(start + 1, sum + i, i);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    dfs(0, 0, 1);
    printf("%d\n", cnt);
}