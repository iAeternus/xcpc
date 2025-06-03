/**
 * @see https://codeforces.com/contest/2008/problem/B
 */
#include <bits/stdc++.h>

const int N = 205;
int a[N][N];
int n;
std::string s;

bool isPerfectSquare(int num) {
    if (num == 1)
        return true;

    int start = 2;
    int end = num;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (mid == num / mid && num % mid == 0)
            return true;

        if (mid > num / mid)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}

bool solve() {
    if (n < 4 || !isPerfectSquare(n)) {
        return false;
    }

    if (s == "1111") {
        return true;
    }

    int cnt1 = 0;
    bool tag = true;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i + 1] == '0') {
            break;
        }
        if (tag && s[i] == '1' && s[i + 1] != '0') {
            cnt1++;
        }
    }

    int cnt2 = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            cnt2++;
        }
    }

    return cnt1 - cnt2 == 2;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> s;
        std::cout << (solve() ? "YES" : "NO") << std::endl;
    }
}