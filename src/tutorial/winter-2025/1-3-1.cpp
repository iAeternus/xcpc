#include <bits/stdc++.h>

void fun(int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        // ...
    }
    fun(n / 2);
    fun(n / 2);
}

void dfs(int n) {
    // retrurn
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
}

int main() {
}