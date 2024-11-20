#include <stdio.h>
using namespace std;

const int N = 50005;
int fa[N * 3];
int n, m;
int ans;

int find(int x) {
    int t = x;
    while (fa[t] != t)
        t = fa[t];
    while (x != t) {
        int temp = fa[x];
        fa[x] = t;
        x = temp;
    }
    return t;
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3 * n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int num, a, b;
        scanf("%d%d%d", &num, &a, &b);
        if (a < 1 || a > n || b < 1 || b > n) {
            ans++;
            continue;
        }
        if (num == 2 && a == b) {
            ans++;
            continue;
        }
        if (num == 1) {  // a,b同类
            if (find(a) == find(b + n) || find(b) == find(a + n))
                ans++;  // 如果a吃b或者b吃a，说明是假话
            else {      // 否则是真话，建立a和b同类的关系
                merge(a, b);
                merge(a + n, b + n);
                merge(a + 2 * n, b + 2 * n);
            }
        } else if (num == 2) {  // a吃b
            if (find(a) == find(b) || find(b) == find(a + n))
                ans++;  // 如果a,b同类或者b吃a，说明是假话
            else {      // 否则是真话，建立a吃b的关系
                merge(a, b + n);
                merge(a + n, b + 2 * n);
                merge(a + 2 * n, b);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
