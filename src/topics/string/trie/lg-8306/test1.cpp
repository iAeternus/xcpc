#include <bits/stdc++.h>

using i64 = long long;
const int N = 3e6 + 10;
const int ALPHABET = 62; // 数字 + 大小写字母，只有小写字母就设为26

int trie[N][ALPHABET];
int cnt[N]; // 前缀计数器
int tot;    // 当前节点总数

int get_idx(char c) {
    if (isdigit(c)) return c - '0';
    if (isupper(c)) return 10 + (c - 'A');
    return 36 + (c - 'a');
}

void init_trie() {
    memset(trie[0], 0, sizeof(trie[0]));
    tot = 0;
}

int create_node() {
    ++tot;
    memset(trie[tot], 0, sizeof(trie[tot]));
    cnt[tot] = 0;
    return tot;
}

void insert(const std::string& s) {
    int p = 0;
    for (char c : s) {
        int idx = get_idx(c);
        if (!trie[p][idx]) {
            trie[p][idx] = create_node();
        }
        p = trie[p][idx];
        ++cnt[p];
    }
}

int query(const std::string& s) {
    int p = 0;
    for (char c : s) {
        int idx = get_idx(c);
        if (!trie[p][idx]) return 0;
        p = trie[p][idx];
    }
    return cnt[p];
}

void solve() {
    init_trie();
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        insert(s);
    }

    while (q--) {
        std::string s;
        std::cin >> s;
        std::cout << query(s) << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}