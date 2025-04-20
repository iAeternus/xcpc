#include <bits/stdc++.h>

const int N = 86400 + 5;
int a[N], d[N];

int calc(int h, int m, int s) {
    return h * 3600 + m * 60 + s + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h, m, s, hh, mm, ss;
        scanf("%d:%d:%d %d:%d:%d", &h, &m, &s, &hh, &mm, &ss);
        int start = calc(h, m, s);
        int end = calc(hh, mm, ss);
        d[start]++;
        d[end + 1]--;
    }

    int ans = 0;
    for(int i = 1; i <= 86400; ++i) {
        a[i] = a[i - 1] + d[i];
        ans = std::max(ans, a[i]);
    }
    printf("%d\n", ans);
}