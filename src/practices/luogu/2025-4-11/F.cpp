#include <bits/stdc++.h>

const int N = 10;
int n;
bool vis[N];
std::vector<int> v;

void dfs(int sum, int x) {
    if(x == n) return;
    if(sum == n) {
        for(int i = 0; i < v.size(); ++i) {
            if(i) {
                std::cout << '+';
            }
            std::cout << v[i];
        }
        std::cout << std::endl;
        return;
    }
    for(int i = x; i <= n - sum; ++i) {
        v.push_back(i);
        dfs(sum + i, i);
        v.pop_back();
    }
}

int main() {
    std::cin >> n;
    dfs(0, 1);
}