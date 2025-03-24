/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582338&page=0
 */
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> mp;
    while (n--) {
        int k;
        std::cin >> k;
        for (int i = 0; i < k; ++i) {
            std::string x;
            std::cin >> x;
            if (k > 1) {
                ++mp[x];
            }
        }
    }

    int m;
    std::cin >> m;
    std::vector<std::string> ans;
    while (m--) {
        std::string x;
        std::cin >> x;
        if (!mp[x]) {
            ans.push_back(x);
            ++mp[x]; // 防止重复
        }
    }

    if (ans.empty()) {
        std::cout << "No one is handsome" << '\n';
    } else {
        for (int i = 0; i < ans.size(); ++i) {
            if (i) {
                std::cout << ' ';
            }
            std::cout << ans[i];
        }
    }
}