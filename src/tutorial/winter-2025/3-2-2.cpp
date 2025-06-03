#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int hash[128] = {0}, ans = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            hash[s[j]]++; // 入
            while (hash[s[j]] > 1) {
                hash[s[i++]]--; // 出
            }
            ans = std::max(ans, j - i + 1);
        }
        return ans;
    }
};

int main() {
}