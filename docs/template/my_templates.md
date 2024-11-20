# Data Structure 数据结构

## DSU 并查集

### 普通并查集

```cpp
const int N = 2e4 + 3;
int fa[N];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    while(x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if(r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}
```

### 带权并查集

1. 封装版

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 封装为结构体
    */
   #include <bits/stdc++.h>
   
   struct Info {
       int min, max, cnt;
   
       Info() {} 
   
       Info(int id)
           : min(id + 1), max(id + 1), cnt(1) {}
   
       void apply(const Info& fy) {
           min = std::min(min, fy.min);
           max = std::max(max, fy.max);
           cnt += fy.cnt;
       }
   };
   
   template <typename Info>
   struct DSU {
       std::vector<int> fa;
       std::vector<Info> info;
   
       DSU() {}
   
       DSU(int n) {
           init(n);
       }
   
       void init(int n) {
           fa.resize(n);
           info.resize(n);
           for(int i = 0; i < n; ++i) {
               fa[i] = i;
               info[i] = Info{i};
           }
       }
   
       int query(int x) {
           while (x != fa[x]) {
               x = fa[x] = fa[fa[x]];
           }
           return x;
       }
   
       bool merge(int x, int y) {
           int fx = query(x);
           int fy = query(y);
           if (fx == fy) {
               return false;
           }
           fa[fy] = fx;
           info[fx].apply(info[fy]);
           return true;
       }
   
       bool same(int x, int y) {
           return query(x) == query(y);
       }
   
       Info get(int x) {
           return info[x];
       }
   };
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       DSU<Info> dsu(n + 1);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               Info fv = dsu.get(dsu.query(v - 1));
               std::cout << fv.min << ' ' << fv.max << ' ' << fv.cnt << std::endl;
           } else {
               std::cin >> u >> v;
               dsu.merge(u - 1, v - 1);
           }
       }
   }
   ```

2. 简化版（下标从0开始）

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 下标从 0 开始
    */
   #include <bits/stdc++.h>
   
   const int N = 3e5 + 7;
   
   struct Info {
       int max, min, cnt;
   } info[N];
   
   int fa[N];
   
   void init(int n) {
       for (int i = 0; i < n; ++i) {
           fa[i] = i;
           info[i] = {i + 1, i + 1, 1};
       }
   }
   
   int query(int x) {
       while (x != fa[x]) {
           x = fa[x] = fa[fa[x]];
       }
       return x;
   }
   
   bool merge(int x, int y) {
       int fx = query(x);
       int fy = query(y);
       if (fx == fy) {
           return false;
       }
       fa[fy] = fx;
       info[fx].max = std::max(info[fx].max, info[fy].max);
       info[fx].min = std::min(info[fx].min, info[fy].min);
       info[fx].cnt += info[fy].cnt;
       return true;
   }
   
   bool same(int x, int y) {
       return query(x) == query(y);
   }
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       init(n);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               int fv = query(v - 1);
               std::cout << info[fv].min << ' ' << info[fv].max << ' ' << info[fv].cnt << std::endl;
           } else {
               std::cin >> u >> v;
               merge(u - 1, v - 1);
           }
       }
   }
   ```

3. 简化版（下标从1开始）

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 下标从 1 开始
    */
   #include <bits/stdc++.h>
   
   const int N = 3e5 + 7;
   
   struct Info {
       int max, min, cnt;
   } info[N];
   
   int fa[N];
   
   void init(int n) {
       for (int i = 1; i <= n; ++i) {
           fa[i] = i;
           info[i] = {i, i, 1};
       }
   }
   
   int query(int x) {
       while (x != fa[x]) {
           x = fa[x] = fa[fa[x]];
       }
       return x;
   }
   
   bool merge(int x, int y) {
       int fx = query(x);
       int fy = query(y);
       if (fx == fy) {
           return false;
       }
       fa[fy] = fx;
       info[fx].max = std::max(info[fx].max, info[fy].max);
       info[fx].min = std::min(info[fx].min, info[fy].min);
       info[fx].cnt += info[fy].cnt;
       return true;
   }
   
   bool same(int x, int y) {
       return query(x) == query(y);
   }
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       init(n);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               int fv = query(v);
               std::cout << info[fv].min << ' ' << info[fv].max << ' ' << info[fv].cnt << std::endl;
           } else {
               std::cin >> u >> v;
               merge(u, v);
           }
       }
   }
   ```

   