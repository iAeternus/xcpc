#include <bits/stdc++.h>

struct Stu {
    std::string s;
    int y, m, d;
    int idx;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Stu> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].s >> v[i].y >> v[i].m >> v[i].d;
        v[i].idx = i;
    }
    std::sort(v.begin(), v.end(), [](const auto& o1, const auto& o2) {
        if(o1.y != o2.y) return o1.y < o2.y;
        if(o1.m != o2.m) return o1.m < o2.m;
        if(o1.d != o2.d) return o1.d < o2.d;
        return o1.idx > o2.idx;
    });

    for(const auto& it : v) {
        std::cout << it.s << std::endl;
    }
}