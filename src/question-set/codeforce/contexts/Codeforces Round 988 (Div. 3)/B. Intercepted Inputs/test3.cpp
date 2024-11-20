#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    std::set<int> st;
    while(t--) {
        st.clear();
        int n;
        std::cin >> n;
        for(int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            st.insert(num);
        }

        n -= 2;

        // 两数之积
        for(const auto& it : st) {
            if(n % it == 0) {
                int m = n / it;
                if(st.contains(m)) {
                    std::cout << m << ' ' << it << std::endl;
                    break;
                }
            }
        }
    }
}