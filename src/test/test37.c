/*
8 0 0 0 0 0 0 0 0 
0 0 3 6 0 0 0 0 0 
0 7 0 0 9 0 2 0 0 
0 5 0 0 0 7 0 0 0 
0 0 0 0 4 5 7 0 0 
0 0 0 1 0 0 0 3 0 
0 0 1 0 0 0 0 6 8 
0 0 8 5 0 0 0 1 0 
0 9 0 0 0 0 4 0 0

8 1 2 7 5 3 6 4 9 
9 4 3 6 8 2 1 7 5 
6 7 5 4 9 1 2 8 3 
1 5 4 2 3 7 8 9 6 
3 6 9 8 4 5 7 2 1 
2 8 7 1 6 9 5 3 4 
5 2 1 9 7 4 3 6 8 
4 3 8 5 2 6 9 1 7 
7 9 6 3 1 8 4 5 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int N = 9;
int mp[9][9];
bool row[9][9 + 1], col[9][9 + 1], grid[3][3][9 + 1];

void show() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", mp[i][j]);
        }
        putchar('\n');
    }
    exit(0);
}

bool check(int x, int y, int num) {
    return row[x][num] || col[y][num] || grid[x / 3][y / 3][num];
}

void dfs(int x, int y) {
    if (y == N) {
        y = 0;
        x++;
    }
    if (x == N) {
        show();
        return;
    }

    if (mp[x][y] != 0) {
        dfs(x, y + 1);
        return;
    }

    for (int num = 1; num <= 9; ++num) {
        if (check(x, y, num)) {
            continue;
        }
        mp[x][y] = num;
        row[x][num] = col[y][num] = grid[x / 3][y / 3][num] = true;
        dfs(x, y + 1);
        row[x][num] = col[y][num] = grid[x / 3][y / 3][num] = false;
        mp[x][y] = 0;
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] != 0) {
                row[i][mp[i][j]] = col[j][mp[i][j]] = grid[i / 3][j / 3][mp[i][j]] = true;
            }
        }
    }

    dfs(0, 0);
}