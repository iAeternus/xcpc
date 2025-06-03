#include <bits/stdc++.h>

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        int count;
        Node() :
                len{0}, link{0}, next{}, count{0} {}
    };
    std::vector<Node> t;
    std::unordered_map<int, int> wordId; // 节点到敏感词 ID 的映射
    std::vector<std::string> words;      // 存储敏感词
    std::vector<int> wordCount;          // 记录每个敏感词的匹配次数
    AhoCorasick() { init(); }
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int add(const std::string& a) {
        int p = 1;
        for (auto c : a) {
            int x = c - 'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        t[p].count++;
        wordId[p] = words.size(); // 映射终止节点到敏感词的 ID
        words.push_back(a);       // 存储敏感词
        wordCount.push_back(0);   // 初始化匹配次数
        return p;
    }
    void work() {
        std::queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                } else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }
    void search(const std::string& text) {
        int p = 1; // 初始状态为根节点
        for (auto c : text) {
            int x = c - 'a'; // 将字符转为对应的数字
            p = next(p, x);  // 移动到下一个状态
            // 统计匹配到的敏感词
            for (int temp = p; temp != 1; temp = t[temp].link) {
                if (t[temp].count > 0 && wordId.find(temp) != wordId.end()) {
                    // 如果该节点是敏感词的结尾，累加对应敏感词的匹配次数
                    wordCount[wordId[temp]]++;
                }
            }
        }
    } // 打印每个敏感词及其匹配次数
    void printResults() {
        for (size_t i = 0; i < words.size(); ++i) {
            std::cout << wordCount[i] << "\n";
        }
    }
    int next(int p, int x) { return t[p].next[x]; }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); /*while (t--) { 		solve(); 	}*/
    int n;
    std::cin >> n;
    std::string s;
    AhoCorasick ac;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        ac.add(s);
    }
    ac.work();
    std::cin >> s;
    ac.search(s);
    ac.printResults();
    return 0;
}