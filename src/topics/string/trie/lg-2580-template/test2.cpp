/**
 * WA了最后一个点
 */
#include <bits/stdc++.h>

const int N = 800000;

struct node {
    bool repeat; // 这个前缀是否重复
    int son[26]; // 26个字母
    int num;     // 这个前缀出现的次数
} t[N];          // trie

int cnt = 1; // 当前新分配的存储位置。把cnt=0留给根结点

void insert(char* s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
        int ch = s[i] - 'a';
        if (t[now].son[ch] == 0) {  // 如果这个字符还没有存过
            t[now].son[ch] = cnt++; // 把cnt位置分配给这个字符
        }
        now = t[now].son[ch]; // 沿着字典树往下走
        t[now].num++;         // 统计这个前缀出现过多少次
    }
}

int find(char* s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
        int ch = s[i] - 'a';
        if (t[now].son[ch] == 0) {
            return 3; // 第一个字符就找不到
        }
        now = t[now].son[ch];
    }

    if (t[now].num == 0) {
        return 3; // 这个前缀没有出现过
    }
    if (t[now].repeat == false) { // 第一次被点名
        t[now].repeat = true;
        return 1;
    }
    return 2;

    // return t[p].num;                    若有需要，返回以s为前缀的单词的数量
}

int main() {
    char s[51];

    int n;
    std::cin >> n;

    while (n--) {
        scanf("%s", s);
        insert(s);
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%s", s);
        int r = find(s);
        if (r == 1)
            puts("OK");
        if (r == 2)
            puts("REPEAT");
        if (r == 3)
            puts("WRONG");
    }
}
