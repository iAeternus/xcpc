/**
 * @see https://www.luogu.com.cn/problem/P2580
 */
#include <bits/stdc++.h>

const int N = 8e5 + 3;

struct node {
    int cnt; // 这个前缀出现的次数
    int son[26]; // 26个字母，26个儿子
    bool repeat; // 这个前缀是否重复
    node() {
        cnt = 0;
        memset(son, false, sizeof son);
        repeat = false;
    }
} trie[N];

int num = 0;

/**
 * 插入字符串
 * @par str 带插入的字符串
 */
void insert(char* s) {
    int v, len = strlen(s);
    int u = 0;
    for (int i = 0; i < len; i++) {
        v = s[i] - 'a';
        if (!trie[u].son[v]) {
            trie[u].son[v] = ++num;
        }
        u = trie[u].son[v];
    }
    trie[u].repeat = 1;
}

/**
 * 查询字符串
 * @par 待查询的字符串
 * @return 1=存在 2=重复 3=不存在
 */
int find(char* s) {
    int v, u = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        v = s[i] - 'a';
        if (!trie[u].son[v]) {
            return 3;
        }
        u = trie[u].son[v];
    }
    if (!trie[u].repeat) {
        return 3;
    }
    if (!trie[u].cnt) {
        trie[u].cnt++;
        return 1;
    }
    return 2;
}

int main() {
    // freopen("P2580_1.in", "r", stdin);

    int n;
    scanf("%d", &n);

    char str[51];
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(str);
    }

    int m;
    scanf("%d", &m);
    while(m--) {
        scanf("%s", str);
        int status = find(str);
        if(status == 1) {
            puts("OK");
        } else if(status == 2) {
            puts("REPEAT");
        } else {
            puts("WRONG");
        }
    }
}