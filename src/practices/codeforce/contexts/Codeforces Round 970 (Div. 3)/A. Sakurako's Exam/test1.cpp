/**
 * @see https://codeforces.com/contest/2008/problem/A
 */
#include <bits/stdc++.h>

// bool solve(int a, int b) {
//     while(a && b) {
//         a -= 2;
//         --b;
//     }

//     if(a) {
//         return !(a & 1);
//     } else {
//         return !(b & 1);
//     }
// }

bool solve(int a, int b) {
    if (a == 0 && b & 1 || b == 0 && a & 1) {
        return false;
    }

    if (b % 2 == 0) {
        if (a % 2 == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (a % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (solve(a, b) ? "YES" : "NO") << std::endl;
    }
}