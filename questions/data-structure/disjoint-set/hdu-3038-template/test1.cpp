/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=3038
 */
/*
题意
给定一段区间的和为x，问当前区间的和与前面的区间有没有冲突，如果有则是错误答案。最后输出错误答案数。
	eg: 
	[1, 10] = 5
	[1, 3] = 2
	[4, 10] = 4
	很显然第三个区间就是错误的，因为[1,3]+[4,10] != [1,10].

sample input
10 5
1 10 100
7 10 28
1 3 32
4 6 41
6 6 1

sample output
1
*/
#include <bits/stdc++.h>

const int N = 2e5 + 9;
int s[N]; // 集
int rank[N]; // 权值，记录当前节点到根节点的距离

int ans;

void init_set() {
    for(int i = 0; i <= N; ++i) {
        s[i] = i;
        rank[i] = 0;
    }
}

int find_set(int x) {
    if(x != s[x]) {
        int t = s[x];
        s[x] = find_set(s[x]); // 路径压缩
        rank[x] += rank[t];
    }
    return s[x];
}

void merge_set(int a, int b, int v) {
    int root_a = find_set(a);
    int root_b = find_set(b);
    if(root_a == root_b) {
        if(rank[a] - rank[b] != v) {
            ++ans;
        }
    } else {
        s[root_a] = root_b; // 合并
        rank[root_a] = rank[b] - rank[a] + v;
    }
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        init_set();
        ans = 0;
        while(m--) {
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            a--; // 变成左开右闭区间，方便区间相加
            merge_set(a, b, v);
        }
        printf("%d\n", ans);
    }
}