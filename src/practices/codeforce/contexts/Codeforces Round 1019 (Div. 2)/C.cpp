#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

vector<bool> compute_prefix_medians(const vector<int>& a, int k) {
    int n = a.size() - 1; // a[1..n]
    vector<bool> res(n + 1, false);
    priority_queue<int> left;                             // 大顶堆，存储较小的前半部分
    priority_queue<int, vector<int>, greater<int>> right; // 小顶堆，存储较大的后半部分

    for (int i = 1; i <= n; ++i) {
        // 插入元素
        if (left.empty() || a[i] <= left.top()) {
            left.push(a[i]);
        } else {
            right.push(a[i]);
        }
        // 调整堆的大小，left的大小应该是 ceil(i/2)
        int expected_size = (i + 1) / 2;
        while (left.size() > expected_size) {
            right.push(left.top());
            left.pop();
        }
        while (left.size() < expected_size) {
            left.push(right.top());
            right.pop();
        }
        // 当前前缀的中位数是否<=k
        res[i] = (left.top() <= k);
    }
    return res;
}

vector<bool> compute_suffix_medians(const vector<int>& a, int k) {
    int n = a.size() - 1;
    vector<bool> res(n + 2, false); // res[i] 表示从i到n的中位数是否<=k
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int i = n; i >= 1; --i) {
        if (left.empty() || a[i] <= left.top()) {
            left.push(a[i]);
        } else {
            right.push(a[i]);
        }
        int expected_size = (n - i + 2) / 2; // ceil(m/2), m = n -i +1
        while (left.size() > expected_size) {
            right.push(left.top());
            left.pop();
        }
        while (left.size() < expected_size) {
            left.push(right.top());
            right.pop();
        }
        res[i] = (left.top() <= k);
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    auto prefix_med = compute_prefix_medians(a, k);
    auto suffix_med = compute_suffix_medians(a, k);

    // 预处理是否有后缀的某个位置i存在true
    vector<bool> has_suffix(n + 2, false);
    has_suffix[n + 1] = false;
    for (int i = n; i >= 1; --i) {
        has_suffix[i] = has_suffix[i + 1] || suffix_med[i];
    }

    bool found = false;
    for (int l = 1; l <= n - 2; ++l) {
        if (prefix_med[l] && has_suffix[l + 2]) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
        return;
    }

    // 检查是否存在一个元素a[i] <=k，并且左边或右边的子数组的中位数满足条件
    vector<int> possible;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= k) {
            possible.push_back(i);
        }
    }

    if (possible.empty()) {
        cout << "NO\n";
        return;
    }

    // 预处理每个位置的前缀中位数是否<=x和后缀中位数是否>=x
    // 但这里简化处理：直接尝试每个可能的i，分割为中间子数组仅包含i
    // 检查左边子数组的中位数 >=a[i]或右边子数组的中位数 <=a[i]
    for (int i : possible) {
        if (i == 1 || i == n) continue;

        // 分割为 l = i-1, r =i，三个子数组是 1..i-1, i, i+1..n
        // 检查左边子数组的中位数 >=a[i]，或者右边子数组的中位数 <=a[i]

        // 左边子数组的中位数是前i-1的prefix_med_val
        bool left_ok = false;
        if (i - 1 >= 1) {
            // 计算前i-1的中位数
            vector<int> temp(a.begin() + 1, a.begin() + i);
            sort(temp.begin(), temp.end());
            int m = temp.size();
            int med = temp[(m - 1) / 2];
            if (med >= a[i]) {
                left_ok = true;
            }
        }

        bool right_ok = false;
        if (i + 1 <= n) {
            // 计算i+1..n的中位数
            vector<int> temp(a.begin() + i + 1, a.end());
            sort(temp.begin(), temp.end());
            int m = temp.size();
            int med = temp[(m - 1) / 2];
            if (med <= a[i]) {
                right_ok = true;
            }
        }

        if (left_ok || right_ok) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
