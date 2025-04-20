#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

inline int read() {
    int res = 0, fu = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') {
            fu = -1;
        }
        c = getchar();
    }
    while (c <= '9' && c >= '0') {
        res = (res << 1) + (res << 3) + c - '0';
        c = getchar();
    }
    return res;
}

struct Node {
    int w, x;
};

Node operator+(const Node& o1, const Node& o2) {
    return {std::min(INF, o1.w + o2.w), o1.x + o2.x};
}

Node min(const Node& o1, const Node& o2) {
    if (o1.w < o2.w) return o1;
    if (o1.w > o2.w) return o2;
    return {o1.w, std::max(o1.x, o2.x)};
}

int main() {
    int b = read(), n = read(), m = read(), k = read();
    std::vector dis(n, std::vector<Node>(n, Node{INF, 0}));
    for (int u = 0; u < n; ++u) {
        dis[u][u] = {0, 0};
    }
    while (m--) {
        int u = read(), v = read(), w = read(), x = read();
        u--, v--;
        dis[u][v] = dis[v][u] = {w, x};
    }

    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dis[i][j].w << ' ';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dis[i][j].x << ' ';
        }
        std::cout << std::endl;
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
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
            max_x = std::max(max_x, dis[s][ans[i]].x);
        }

        bool fst = true;
        for (auto u : ans) {
            if (!fst) std::cout << ' ';
            if (dis[s][u].x == max_x) {
                fst = false;
                std::cout << u + 1;
            }
        }
        std::cout << std::endl;
    }
}