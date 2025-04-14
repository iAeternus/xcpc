#include <bits/stdc++.h>

const int N = 205;
int a[N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        std::vector<int> v;
        for (int j = i; j < i + n; j++) {
            v.push_back(a[j]);
        }
        int sum = 0, cnt = 0;
        while (!v.empty()) {
            for (int k = 0; k < v.size(); k++) {
                ++cnt;
                if (cnt == v[k]) {
                    sum += v[k];
                    v[k] = 0;
                    cnt = 0;
                }
            }
            v.erase(std::remove(v.begin(), v.end(), 0), v.end());
            if (cnt >= 100) break;
        }
        ans = std::max(ans, sum);
    }
    std::cout << ans << std::endl;
}