/**
 * @see https://codeforces.com/contest/2037/problem/C
 */
#include <bits/stdc++.h>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> nums;
    while (t--) {
        nums.clear();
        int n;
        std::cin >> n;

        if (n <= 4) {
            std::cout << -1 << std::endl;
            continue;
        }

        for (int i = n; i >= 1;) {
            if (isPrime(i + i - 1)) {
                nums.push_back(i - 1);
                std::cout << i << ' ' << i - 2 << ' ';
                i -= 3;
            } else {
                std::cout << i << ' ' << --i << ' ';
                // --i;
            }
        }

        for (const auto& num : nums) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}