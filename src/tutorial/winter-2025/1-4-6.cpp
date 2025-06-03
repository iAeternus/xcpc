#include <bits/stdc++.h>

struct X {
    int x, y;
};

struct cmp {
    bool operator()(const X& o1, const X& o2) const {
        return o1.x < o2.x;
    }
};

int main() {
    std::set<X, cmp> st;

    st.insert({1, 3});
    st.insert({2, 3});
    st.insert({0, 3});

    for (const auto& it : st) {
        std::cout << it.x << std::endl;
    }
}