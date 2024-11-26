// #include <bits/stdc++.h>

// std::unordered_map<int, std::pair<int, bool>> mp;

// int main() {
//     int t;
//     std::cin >> t;
//     while (t--) {
//         mp.clear();
//         std::string a;
//         std::cin >> a;
//         for (int i = 0; i < a.size();) {
//             if (a[i] == '2') {
//                 mp.insert({i, {-1, true}});
//                 ++i;
//                 continue;
//             }

//             int cnt = 1, j = i + 1;
//             while (a[i] == a[j++]) {
//                 ++cnt;
//             }
//             mp.insert({i, {cnt, true}});
//             i += cnt;
//         }

//         for (auto& [idx, cnt] : mp) {
//             // std::cout << idx << ' ' << cnt << std::endl;
//             if (cnt.first != -1) {
//                 if (cnt.first & 1) {
//                     mp[idx] = {1, true};
//                 } else {
//                     mp[idx] = {INT_MIN, false};
//                 }
//             }
//         }

//         for (const auto& [idx, cnt] : mp) {
//             if (cnt.second) {
//                 // std::cout << idx << ' ' << cnt.first << std::endl;
//                 if(cnt.first == -1) {

//                 }
//             }
//         }
//     }
// }


// //na

// for(int i =0;i < n;i++)
// {
                                                                                                                                                                                                                
// }njing
// jingewqnan