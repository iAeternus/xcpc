#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

// int main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> a[i];
//     }
//     std::sort(a.begin(), a.end());
//     int ans = 0;
//     for (int i = 0, j = 0; i < n; i = j) {
//         while (j < n && a[j] == a[i]) {
//             j++;
//         }
//         ans += i * (j - i) * (n - j);
//     }
//     std::cout << ans << std::endl;
// }

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::unordered_map<int, int> count;
    for (auto x : a) {
        count[x]++;
    }
    int res = 0, t = 0;
    for (const auto& [k, v] : count) {
        res += t * v * (n - t - v);
        t += v;
    }
    std::cout << res << std::endl;
}