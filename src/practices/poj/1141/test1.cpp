/**
 * @see http://poj.org/problem?id=1141
 */
#include <iostream>
#include <string>
#include <cstring>
#include <climits>

const int N = 105;
std::string s;
int dp[N][N], mark[N][N];

bool isValid(char a, char b) {
    return a == '(' && b == ')' || a == '[' && b == ']';
}

void show(int l, int r) {
    if (l > r) return;
    if (l == r) {
        if (s[l - 1] == '(' || s[l - 1] == ')') {
            std::cout << "()";
        } else {
            std::cout << "[]";
        }
        return;
    }

    if (mark[l][r]) {
        show(l, mark[l][r]);
        show(mark[l][r] + 1, r);
    } else {
        std::cout << s[l - 1];
        show(l + 1, r - 1);
        std::cout << s[r - 1];
    }
}

int main() {
    while (std::getline(std::cin, s)) {
        std::memset(dp, 0, sizeof dp);
        std::memset(mark, 0, sizeof mark);
        for (int i = 1; i <= s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= s.size(); ++len) {
            for (int i = 1; i + len - 1 <= s.size(); ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                if (isValid(s[i - 1], s[j - 1])) {
                    dp[i][j] = dp[i + 1][j - 1];
                    mark[i][j] = 0;
                }
                for (int k = i; k < j; ++k) {
                    if (dp[i][k] + dp[k + 1][j] < dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                        mark[i][j] = k;
                    }
                }
            }
        }
        show(1, s.size());
        std::cout << std::endl;
    }
}