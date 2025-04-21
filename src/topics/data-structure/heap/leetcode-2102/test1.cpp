#include <bits/stdc++.h>

class SORTracker {
public:
    struct Node {
        std::string name;
        int score;

        bool operator<(const Node& other) const {
            if (score != other.score) return score < other.score;
            return name > other.name;
        }

        bool operator>(const Node& other) const {
            if (score != other.score) return score > other.score;
            return name < other.name;
        }
    };

    int cur;
    std::priority_queue<Node> ge;                                    // 大根堆
    std::priority_queue<Node, std::vector<Node>, std::greater<>> le; // 小根堆

    SORTracker() :
            cur{1} {}

    void add(std::string name, int score) {
        Node n{name, score};
        if (le.empty() || le.top() < n) {
            le.push(n);
        } else {
            ge.push(n);
        }

        while (le.size() > cur) {
            ge.push(le.top());
            le.pop();
        }
        while (le.size() < cur && !ge.empty()) {
            le.push(ge.top());
            ge.pop();
        }
    }

    std::string get() {
        auto res = le.top().name;
        ++cur;
        while (le.size() < cur && !ge.empty()) {
            le.push(ge.top());
            ge.pop();
        }
        return res;
    }
};

int main() {
}