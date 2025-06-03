#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> nums;
    while (t--) {
        nums.clear();
        int n;
        std::cin >> n;

        if (n < 5) {
            std::cout << -1 << std::endl;
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (i & 1 && i != 5) {
                nums.push_back(i);
            }
        }

        nums.push_back(5);
        nums.push_back(4);

        for (int i = 1; i <= n; ++i) {
            if (!(i & 1) && i != 4) {
                nums.push_back(i);
            }
        }

        for (const auto& num : nums) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}