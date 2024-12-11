/*
Dancing Link算法
求解超难数独：
9 0 0 8 0 0 0 0 0
0 0 0 0 0 0 5 0 0
0 0 0 0 0 0 0 0 0
0 2 0 0 1 0 0 0 3
0 1 0 0 0 0 0 6 0
0 0 0 4 0 0 0 7 0
7 0 8 6 0 0 0 0 0
0 0 0 0 3 0 1 0 0
4 0 0 0 0 0 2 0 0
*/
#include <bits/stdc++.h>

const int N = 9;
const int M = 1e5 + 3;
int head, cnt;
int mp[N][N], u[M], d[M], l[M], r[M], row[M], col[M], num[M], ans[M];
std::vector<int> v[M];

void init() {
    for (int i = 0; i <= 324; ++i) {
        u[i] = i;
        d[i] = i;
        l[i] = i - 1;
        r[i] = i + 1;
    }
    l[head] = 324;
    r[324] = head;
    cnt = 325;
}

void addRow(int x) {
    int first = cnt;
    for (int i = 0; i < v[x].size(); ++i) {
        int j = v[x][i];
        u[cnt] = u[j];
        d[u[j]] = cnt;
        u[j] = cnt;
        d[cnt] = j;
        l[cnt] = cnt - 1;
        r[cnt] = cnt + 1;
        col[cnt] = j;
        row[cnt] = x;
        ++num[j];
        ++cnt;
    }
    l[first] = cnt - 1;
    r[cnt - 1] = first;
}

void remove(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
    for (int i = d[x]; i != x; i = d[i]) {
        for (int j = r[i]; j != i; j = r[j]) {
            u[d[j]] = u[j];
            d[u[j]] = d[j];
            --num[col[j]];
        }
    }
}

void restore(int x) {
    for (int i = u[x]; i != x; i = u[i]) {
        for (int j = l[i]; j != i; j = l[j]) {
            d[u[j]] = j;
            u[d[j]] = j;
            ++num[col[j]];
        }
    }
    r[l[x]] = x;
    l[r[x]] = x;
}

bool dance(int dep) {
    if (r[head] == head) {
        int x, y, z;
        for (int i = 0; i < dep; ++i) {
            x = (ans[i] - 1) / N / N;
            y = (ans[i] - 1) / N % N;
            z = ans[i] % N;
            if (!z) {
                z = N;
            }
            mp[x][y] = z;
        }
        return 1;
    }

    int now = r[head];
    for (int i = r[head]; i != head; i = r[i]) {
        if (num[i] < num[now]) {
            now = i;
        }
    }
    remove(now);
    for (int i = d[now]; i != now; i = d[i]) {
        ans[dep] = row[i];
        for (int j = r[i]; j != i; j = r[j]) {
            remove(col[j]);
        }
        if (dance(dep + 1)) {
            return 1;
        }
        for (int j = l[i]; j != i; j = l[j]) {
            restore(col[j]);
        }
    }
    restore(now);
    return 0;
}

int main() {
    init();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> mp[i][j];
            for (int k = 1; k <= N; ++k) {
                if (mp[i][j] != k && mp[i][j]) {
                    continue;
                }
                int x = i * N * N + j * N + k;
                v[x].push_back(i * N + j + 1);
                v[x].push_back(i * N + 81 + k);
                v[x].push_back(j * N + 81 * 2 + k);
                v[x].push_back(81 * 3 + (i / 3 * 3 + j / 3) * N + k);
                addRow(x);
            }
        }
    }

    dance(0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << mp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}