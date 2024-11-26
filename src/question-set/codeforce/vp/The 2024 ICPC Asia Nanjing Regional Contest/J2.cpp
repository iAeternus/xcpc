#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 3;
int n, m, k;
int will_have[N];  // 储存 添加当前一个朋友就能多看到的评论数
bool friends[N];   // 储存 当前已有的好友
int x, y;
std::map<std::pair<int, int>, int> edge;              // 储存 都不是好友的两人间的消息数(看做一个有权边,两个节点都不是好友)
std::vector<std::pair<int, int>> infomation_of_edge;  // 储存 边的两个节点 与上面对应

void solve() {
    edge.clear();
    infomation_of_edge.clear();

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        friends[i] = 0;
        will_have[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> x;
        friends[x] = 1;
    }
    int ans = 0, cnt = 0, cnn = 0;
    for (int i = 1; i <= m; i++) {
        std::cin >> x >> y;
        if (friends[x] && friends[y]) {
            ans++;
        } else if (friends[x] && !friends[y]) {
            will_have[y]++;  // 添加一个
        } else if (!friends[x] && friends[y]) {
            will_have[x]++;  // 添加一个
        } else {
            if (x == y) {
                will_have[x]++;
            } else {
                if (x > y) {
                    swap(x, y);
                }
                infomation_of_edge.push_back({x, y});
                edge[{x, y}]++;
            }
        }
    }

    for (int i = 0; i < infomation_of_edge.size(); i++) {  // 能多看到的评论数 = 两人间相互的评论 + 一边与已有好友的评论 + 另一边与已有好友的评论 ,取最大值
        x = edge[infomation_of_edge[i]] + will_have[infomation_of_edge[i].first] + will_have[infomation_of_edge[i].second];
        cnt = max(cnt, x);
    }
    sort(will_have, will_have + 1 + k);
    cnn = will_have[k] + will_have[k - 1];  // 取 非好友人 与 已有好友 间评论数最大的两个(可能会出现有 非好友人 与 已有好友 间评论非常多,但与 其他非好友人 之间的评论很少的情况)
    ans += max(cnn, cnt);                   // ans加两种情况中大的那一个
    std::cout << ans << '\n';
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}