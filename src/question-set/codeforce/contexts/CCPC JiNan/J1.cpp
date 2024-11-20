#include <bits/stdc++.h>

std::map<int, int> mp1;
std::map<int, int> mp2;
std::map<int, int> mp3;

std::vector<std::tuple<int, int, int>> p;
// #define endl "\n"
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        mp1.clear();
        mp2.clear();
        mp3.clear();
        p.clear();
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            std::cin >> x >> y >> z;
            p.push_back({x, y, z});
            mp1[x]++;
            mp2[y]++;
            mp3[z]++;
        }

        std::vector<int> f;
        std::map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            auto [x, y, z] = p[i];
            int xx = mp1[x] - 1;
            int yy = mp2[y] - 1;
            int zz = mp3[z] - 1;
            int tmp = std::max(xx, std::max(yy, zz));
            f.push_back(tmp);
            mp[tmp]++;
        }
        auto it= mp.begin();
        long long ans =0;
        for (int k = 0; k < n; ++k) {
            if(it == mp.end())
            {
                std::cout<<n<<" ";
            }
            else if(k <= it->first)
            {
                std::cout<<ans<<" ";
            }
            else
            
            {
                while( k > it->first)
                {
                    if(it == mp.end())
                    {
                        
                        ans = n;break;
                    }
                    ans+=it->second;
                    it++;
                }
                std::cout<<ans<<" ";
            }
           
        }
        std::cout<<"\n";
        // for(const auto&[k, v] : mp) {
        //     if()
        // }

        // // for(const auto& it : f) {
        // //     std::cout << it << ' ';
        // // }
        // // std::cout << std::endl;

        // std::sort(f.begin(), f.end());

        // for (int k = 0; k < n; ++k) {
        //     auto it = std::lower_bound(f.begin(), f.end(), k);
        //     if(it == f.end()) {
        //         std::cout << 0 << ' ';
        //         continue;
        //     }
        //     std::cout << *it << ' ';
        //     // std::cout << * << ' ';
        // }
        // std::cout << '\n';

        // for(int k = 0; k < n; ++k) {
        //     // if(f[0] >= k)
        //     //     std::cout << 0 << ' ';
        //     //     continue;
        //     // }

        //     int cnt = 0;
        //     for(const auto& it : f) {
        //         if(it < k) {
        //             ++cnt;
        //         }
        //     }
        //     std::cout << cnt << ' ';
        // }

        // std::cout << '\n';
    }
}