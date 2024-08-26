#include <bits/stdc++.h>

const int N = 1e3 + 5;
int mp[N][N];
int n;

#define RED_COLOR_CODE "\033[1;31m"     // 设置文本颜色为红色
#define GREEN_COLOR_CODE "\033[1;32m"   // 设置文本颜色为绿色
#define YELLOW_COLOR_CODE "\033[1;33m"  // 设置文本颜色为黄色
#define BLUE_COLOR_CODE "\033[1;34m"    // 设置文本颜色为蓝色
#define DEFAULT_COLOR_CODE "\033[0m"    // 恢复默认文本颜色

void init(int x, int y) {
    mp[x][y] = 0;
}

void print_mp() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mp[i][j] == 1) {
                std::cout << RED_COLOR_CODE << mp[i][j] << DEFAULT_COLOR_CODE << ' ';
            } else if (mp[i][j] == 2) {
                std::cout << BLUE_COLOR_CODE << mp[i][j] << DEFAULT_COLOR_CODE << ' ';
            } else if (mp[i][j] == 3) {
                std::cout << GREEN_COLOR_CODE << mp[i][j] << DEFAULT_COLOR_CODE << ' ';
            } else if (mp[i][j] == 4) {
                std::cout << YELLOW_COLOR_CODE << mp[i][j] << DEFAULT_COLOR_CODE << ' ';
            } else {
                std::cout << mp[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#define SHOW_MP

#ifdef SHOW_MP
void show(int x, int y, int idx) {
    if (idx == 1) {
        mp[x][y] = mp[x][y - 1] = mp[x - 1][y] = 1;
    }
    if (idx == 2) {
        mp[x][y] = mp[x - 1][y] = mp[x][y + 1] = 2;
    }
    if (idx == 3) {
        mp[x][y] = mp[x][y - 1] = mp[x + 1][y] = 3;
    }
    if (idx == 4) {
        mp[x][y] = mp[x + 1][y] = mp[x][y + 1] = 4;
    }

    // test
    // print_mp();
    // puts("=========================================");
}
#else
void show(int x, int y, int idx) {
    std::cout << x << ' ' << y << ' ' << idx << std::endl;
}
#endif

void dfs(int begin_x, int begin_y, int end_x, int end_y, int x, int y) {
    // 变成了2 * 2
    if (end_x - begin_x == 1 && end_y - begin_y == 1) {
        if (x == begin_x && y == begin_y) {
            show(end_x, end_y, 1);
        }
        if (x == begin_x && y == end_y) {
            show(end_x, begin_y, 2);
        }
        if (x == end_x && y == begin_y) {
            show(begin_x, end_y, 3);
        }
        if (x == end_x && y == end_y) {
            show(begin_x, begin_y, 4);
        }
        return;
    }

    int mid_x = ((end_x - begin_x + 1) >> 1) + begin_x - 1;
    int mid_y = ((end_y - begin_y + 1) >> 1) + begin_y - 1;

    if (x <= mid_x && y <= mid_y) {
        dfs(begin_x, begin_y, mid_x, mid_y, x, y);
        show(mid_x + 1, mid_y + 1, 1);
        dfs(mid_x + 1, begin_y, end_x, mid_y, mid_x + 1, mid_y);
        dfs(begin_x, mid_y + 1, mid_x, end_y, mid_x, mid_y + 1);
        dfs(mid_x + 1, mid_y + 1, end_x, end_y, mid_x + 1, mid_y + 1);
    }
    if (x <= mid_x && y > mid_y) {
        dfs(begin_x, mid_y + 1, mid_x, end_y, x, y);
        show(mid_x + 1, mid_y, 2);
        dfs(begin_x, begin_y, mid_x, mid_y, mid_x, mid_y);
        dfs(mid_x + 1, begin_y, end_x, mid_y, mid_x + 1, mid_y);
        dfs(mid_x + 1, mid_y + 1, end_x, end_y, mid_x + 1, mid_y + 1);
    }
    if (x > mid_x && y <= mid_y) {
        dfs(mid_x + 1, begin_y, end_x, mid_y, x, y);
        show(mid_x, mid_y + 1, 3);
        dfs(begin_x, begin_y, mid_x, mid_y, mid_x, mid_y);
        dfs(begin_x, mid_y + 1, mid_x, end_y, mid_x, mid_y + 1);
        dfs(mid_x + 1, mid_y + 1, end_x, end_y, mid_x + 1, mid_y + 1);
    }
    if (x > mid_x && y > mid_y) {
        dfs(mid_x + 1, mid_y + 1, end_x, end_y, x, y);
        show(mid_x, mid_y, 4);
        dfs(begin_x, begin_y, mid_x, mid_y, mid_x, mid_y);
        dfs(mid_x + 1, begin_y, end_x, mid_y, mid_x + 1, mid_y);
        dfs(begin_x, mid_y + 1, mid_x, end_y, mid_x, mid_y + 1);
    }
}

void dfs_facade(int k, int x, int y) {
    n = (1 << k);  // 2^k
    dfs(1, 1, n, n, x, y);
}

int main() {
    int k, x, y;
    std::cin >> k >> x >> y;
    init(x, y);
    dfs_facade(k, x, y);
    
    print_mp();
}