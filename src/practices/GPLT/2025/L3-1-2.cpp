#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

inline int read() {
    int res = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        res = (res << 1) + (res << 3) + c - '0';
        c = getchar();
    }
    return res;
}

struct Node {
    int w, x;
};

Node operator+(const Node& n1, const Node& n2) {
    return {std::min(INF, n1.w + n2.w), n1.x + n2.x};
}

Node min(const Node& n1, const Node& n2) {
    if (n1.w < n2.w) return n1;
    if (n1.w > n2.w) return n2;
    return {n1.w, std::max(n1.x, n2.x)};
}

int main() {
    int b = read(), n = read(), m = read(), k = read();
    std::vector dis(n, std::vector<Node>(n, {INF, 0}));
    for (int i = 0; i < n; ++i) {
        dis[i][i] = {0, 0};
    }

    for (int i = 0; i < m; ++i) {
        int u = read(), v = read(), w = read(), x = read();
        u--, v--;
        dis[u][v] = dis[v][u] = {w, x};
    }

    // floyd
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            if (dis[u][k].w == INF) continue;
            for (int v = 0; v < n; ++v) {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    while (k--) {
        int s = read();
        s--;
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dis[s][i].w <= b && i != s) {
                ans.push_back(i);
            }
        }

        if (ans.empty()) {
            std::cout << "T_T\n";
            continue;
        }

        int max_x = 0;
        bool fst = true;
        for (auto t : ans) {
            if (fst)
                fst = false;
            else
                std::cout << ' ';
            std::cout << t + 1;
            max_x = std::max(max_x, dis[s][t].x);
        }
        std::cout << std::endl;

        fst = true;
        for (auto t : ans) {
            if (dis[s][t].x == max_x) {
                if (fst)
                    fst = false;
                else
                    std::cout << ' ';
                std::cout << t + 1;
            }
        }
        std::cout << std::endl;
    }
}