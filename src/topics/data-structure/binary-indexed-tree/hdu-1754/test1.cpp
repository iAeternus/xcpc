/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1754
 */
/*
Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

Sample Output
5
6
5
9

*/
#include <bits/stdc++.h>

const int N = 2e5 + 10;
int n, m, a[N], tree[N];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i)) {
        tree[x] = val;
        for(int i = 1; i < lowbit(x); i <<= 1) {
            tree[x] = std::max(tree[x], tree[x - i]);
        }
    }
}

int query(int left, int right) {
    int ans = 0;
    while(left <= right) {
        ans = std::max(ans, a[right]);
        --right;
        while(right - left >= lowbit(right)) {
            ans = std::max(ans, tree[right]);
            right -= lowbit(right);
        }
    }
    return ans;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        memset(tree, 0, sizeof tree);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            update(i, a[i]);
        }

        while(m--) {
            char s[5];
            int A, B;
            scanf("%s %d %d", &s, &A, &B);
            if(s[0] == 'Q') {
                printf("%d\n", query(A, B));
            } else {
                a[A] = B;
                update(A, B);
            }
        }
    }
}