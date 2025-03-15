/**
 * @see https://codeforces.com/gym/105484/problem/G
 */
#include <bits/stdc++.h>

const int N = 1e5 + 7;
std::vector<int> g[N];
int n, siz[N], root, ans, res, ot, l, r;
bool ok, bk[N];
std::vector<std::pair<int, int>> rt;

void add(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int ask(int x, int y) {
    int z;
    std::cout << "? " << x << ' ' << y << std::endl;
    std::cin >> z;
    return z;
}

void ret(int x) {
    std::cout << "! " << x << std::endl;
    ok = true;
}

// 子树siz
void getSiz(int p, int fa) {
    siz[p] = 1;
    for(const auto& it : g[p]) {
        if(it != fa && bk[it]) {
            getSiz(it, p);
            siz[p] += siz[it];
        }
    }
}

// 找重心
int dfs(int u, int p) {
    siz[u] = 1;
    std::vector<std::pair<int, int>> tmp;
    for(const auto& v : g[u]) {
        if(v != p && bk[v]) {
            siz[u] += dfs(v, u);
            tmp.push_back({siz[v], v});
        }
    }
    if(u != p && bk[p]) {
        tmp.push_back({res - siz[u], p});
    }
    if(tmp.size() <= 1) {
        return siz[u];
    }
    std::sort(tmp.begin(), tmp.end());
    if(tmp.size() == 2) {
        if(ans > tmp[1].first) {
            ans = tmp[1].first;
            rt = tmp;
            root = u;
        }
    } else {
        int mx = std::max(tmp[0].first + 1, tmp[2].first);
        if(ans > mx) {
            ans = mx;
            rt = tmp;
            root = u;
        }
    }
    return siz[u];
}

void process(int cur) {
    if(ok) return;
    ans = 1e9;
    getSiz(cur, cur);
    res = siz[cur];
    if(res <= 2) {
        r = 0;
        for(const auto& it : g[cur]) {
            if(bk[it]) {
                r = it;
            }
        }
        if(!r) {
            ret(cur);
        } else {
            ret(ask(cur, r) == 0 ? cur : r);
        }
    } else {
        dfs(cur, cur);
        if(rt.size() == 3) {
            l = rt[1].second;
            r = rt[2].second;
        } else {
            l = rt[0].second;
            r = rt[1].second;
        }
        ot = ask(l, r);
        if(ot == 0) {
            bk[root] = false;
            process(l);
        } else if(ot == 1) {
            bk[l] = bk[r] = false;
            process(root);
        } else {
            bk[root] = false;
            process(r);
        }
    }
}

void solve() {
    std::cin >> n;
    ok = false;
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        bk[i] = true;
    }
    for(int i = 1; i <= n; ++i) {
        int l, r;
        std::cin >> l >> r;
        if(l) add(i, l);
        if(r) add(i, r);
    }
    process(1);
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}