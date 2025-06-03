/**
 * @see https://www.luogu.com.cn/problem/P2580
 */
#include <bits/stdc++.h>

const int N = 8e5 + 3;

struct node {
    int num;     // 这个前缀出现的次数
    int son[26]; // 26个字母，26个儿子
    bool repeat; // 这个前缀是否重复
    node() {
        num = 0;
        memset(son, false, sizeof(son));
        repeat = false;
    }
} trie[N];

int cnt = 0;

/**
 * 插入字符串
 * @par s 待插入的字符串
 */
void insert(char* s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
        int ch = s[i] - 'a';
        if (!trie[now].son[ch]) {
            trie[now].son[ch] = ++cnt;
        }
        now = trie[now].son[ch];
    }
    trie[now].repeat = true;
}

/**
 * 查询字符串
 * @par s 待查询的字符串
 * @return 1=存在 2=重复 3=不存在
 */
int find(char* s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
        int ch = s[i] - 'a';
        if (!trie[now].son[ch]) {
            return 3;
        }
        now = trie[now].son[ch];
    }
    if (!trie[now].repeat) {
        return 3;
    }
    if (!trie[now].num) {
        trie[now].num++;
        return 1;
    }
    return 2;
    // return trie[now].num; // 若有需要，返回以s为前缀的单词的数量
}

int main() {
    // freopen("P2580_1.in", "r", stdin);

    int n;
    scanf("%d", &n);

    char str[51];
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(str);
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%s", str);
        int status = find(str);
        if (status == 1) {
            puts("OK");
        } else if (status == 2) {
            puts("REPEAT");
        } else {
            puts("WRONG");
        }
    }
}