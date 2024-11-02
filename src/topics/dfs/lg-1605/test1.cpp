/**
 * @see https://www.luogu.com.cn/problem/P1605
 */
#include <bits/stdc++.h>

const int N = 10;
int n, m, t, sx, sy, fx, fy;
int mp[N][N], vis[N][N];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int ans;

void dfs(int x, int y) {
    if(x == fx && y == fy) {
        ++ans;
        return;
    }

    for(int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && !vis[new_x][new_y] && !mp[new_x][new_y]) {
            vis[x][y] = 1;
            dfs(new_x, new_y);
            vis[x][y] = 0;
        }
    }
}

int main() {
    scanf("%d %d %d %d %d %d %d", &n, &m, &t, &sx, &sy, &fx, &fy);
    while(t--) {
        int x, y;
        scanf("%d %d", &x, &y);
        mp[x][y] = 1;
    }
    dfs(sx, sy);
    printf("%d\n", ans);
}