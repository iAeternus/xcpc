# **Chapter 1 导言、算法分析与STL**

## 1.1 OJ

* [Codeforces](https://codeforces.com/)
* [Virtual Judge](https://vjudge.net/)
* [牛客网 - 找工作神器|笔试题库|面试经验|实习招聘内推，求职就业一站解决_牛客网](https://www.nowcoder.com/)
* [AtCoder](https://atcoder.jp/)
* [首页 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/)
* [Welcome To PKU JudgeOnline](http://poj.org/)
* [Welcome to Hangzhou Dianzi University Online Judge](https://acm.hdu.edu.cn/)
* [力扣 (LeetCode) 全球极客挚爱的技术成长平台](https://leetcode.cn/)

## 1.2 Resources

* [OI Wiki - OI Wiki](https://oi-wiki.org/)

## 1.3 算法分析

* [复杂度简介 - OI Wiki](https://oi-wiki.org/basic/complexity/#大-θ-符号)

### 1.3.1 渐进分析

1. 渐进记号在数学上实际是集合，**等于**实际上是**属于**或**包含**

2. $\Theta$符号：

   ![](F:\documents\algorithm tutorial with c++\assets\大Theta符号2.png)

3. $O$符号：表示函数的一个在常量因子内的上界

4. $\Omega$符号：表示函数的一个在常量因子内的下界

### 1.3.2 求解递归式

1. 递归式的编写
2. 主方法解递归式：[主定理(Master Theorem) - 知乎](https://zhuanlan.zhihu.com/p/113406812)

## 1.4 STL

参考[C++ 参考手册 - cppreference.com](https://zh.cppreference.com/w/cpp)

## 1.5 Question

* 我们学习了三种渐进符号：渐进紧确界、渐进上界与渐进下界。那么使用这些渐进分析算法有什么意义呢？
* 为什么其中渐进上界是较为常用的渐进符号呢？
* 还有哪些算法分析方法？适用于哪些情况？

# **Chapter 2 模拟、枚举与贪心**

## 2. 1 模拟

* [P1138 第 k 小整数 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1138)
* [Problem - A - Codeforces](https://codeforces.com/contest/2037/problem/0)
* [Problem - B - Codeforces](https://codeforces.com/contest/2044/problem/B)
* [T539827 202411H Enemy - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/T539827)

## 2.2 枚举

* 试除法：[【算法拾遗】试除法 - Trial Division - 知乎](https://zhuanlan.zhihu.com/p/60745545)
* [P2241 统计方形（数据加强版） - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P2241)

## 2.3 贪心

* 部分背包：[算法设计与分析_中国大学MOOC(慕课)](https://www.icourse163.org/learn/BUAA-1449777166?tid=1473349466#/learn/content?type=detail&id=1261110201&cid=1298124170)
* [Problem - A - Codeforces](https://codeforces.com/contest/2030/problem/0)

# **Chapter 3 双指针、滑动窗口**

## 3.1 双指针

1. 快慢指针 
   * [27. 移除元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-element/)
   * [283. 移动零 - 力扣（LeetCode）](https://leetcode.cn/problems/move-zeroes/description/)
2. 左右指针 
   * [977. 有序数组的平方 - 力扣（LeetCode）](https://leetcode.cn/problems/squares-of-a-sorted-array/)
   * [11. 盛最多水的容器 - 力扣（LeetCode）](https://leetcode.cn/problems/container-with-most-water/description/)

## 3.2 滑动窗口

1. [209. 长度最小的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)
1. [3. 无重复字符的最长子串 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/)

# **Chapter 4 高精度**

```cpp
constexpr int N = 1000;
struct BigInt {
    int a[N]; // 逆序存储
    BigInt(int x = 0) :
            a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt& operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt& operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt& operator+=(const BigInt& x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& o, const BigInt& a) {
    int t = N - 1;
    while (a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}
```



# **Chapter 5 二分、前缀和与差分**

略

# **Chapter 6 分治与搜索**

## 6.1 分治

* 快速排序

  ```cpp
  #include <bits/stdc++.h>
  
  template<typename T, typename C>
  int partition(std::vector<T>& vec, int left, int right, C compare) {
      T pivot = vec[right];
      int i = left;
      for(int j = left; j < right; ++j) {
          if(compare(vec[j], pivot)) { // <
              std::swap(vec[i++], vec[j]);
          }
      }
      std::swap(vec[i], vec[right]);
      return i; // 主元的索引
  }
  
  template<typename T, typename C>
  void sort(std::vector<T>& vec, int left, int right, C compare) {
      if(left >= right) return;
      int pivotIdx = partition(vec, left, right, compare);
      sort(vec, left, pivotIdx - 1, compare); // 左
      sort(vec, pivotIdx + 1, right, compare); // 右
  }
  
  /**
   * @brief 最终的接口
   */
  template<typename T, typename C>
  void sort(std::vector<T>& vec, C compare) {
      sort(vec, 0, vec.size() - 1, compare);
  }
  
  int main() {
      std::vector<int> nums = {6, 5, 7, 4, 8, 3, 9, 2, 0, 1};
      sort(nums, std::less<int>{});
      for(const auto& num : nums) {
          std::cout << num << ' ';
      }
      std::cout << std::endl;
  
      sort(nums, [](int a, int b) {
          return a > b;
      });
      for(const auto& num : nums) {
          std::cout << num << ' ';
      }
      std::cout << std::endl;
  }
  ```

  

* 归并排序

  ```cpp
  #include <bits/stdc++.h>
  
  template <typename T, typename C>
  void merge(std::vector<T>& vec, int left, int mid, int right, C compare) {
      int n1 = mid - left + 1;
      int n2 = right - mid;
      std::vector<T> leftVec(n1), rightVec(n2);
      int i, j;
      for (i = 0; i < n1; ++i) {
          leftVec[i] = vec[left + i];
      }
      for (j = 0; j < n2; ++j) {
          rightVec[j] = vec[mid + j + 1];
      }
  
      i = j = 0;
      int pos = left;
      while (i < n1 && j < n2) {
          if (compare(leftVec[i], rightVec[j])) {
              vec[pos++] = leftVec[i++];
          } else {
              vec[pos++] = rightVec[j++];
          }
      }
      while (i < n1) {
          vec[pos++] = leftVec[i++];
      }
      while (j < n2) {
          vec[pos++] = rightVec[j++];
      }
  }
  
  template <typename T, typename C>
  void sort(std::vector<T>& vec, int left, int right, C compare) {
      if (left >= right) return;
      int mid = left + ((right - left) >> 1); // (left + right) / 2
      sort(vec, left, mid, compare);
      sort(vec, mid + 1, right, compare);
      merge(vec, left, mid, right, compare);
  }
  
  template <typename T, typename C>
  void sort(std::vector<T>& vec, C compare) {
      sort(vec, 0, vec.size() - 1, compare);
  }
  
  int main() {
      std::vector<int> nums = {6, 5, 7, 4, 8, 3, 9, 2, 0, 1};
      sort(nums, std::less<int>{});
      for(const auto& num : nums) {
          std::cout << num << ' ';
      }
      std::cout << std::endl;
  
      sort(nums, [](int a, int b) {
          return a > b;
      });
      for(const auto& num : nums) {
          std::cout << num << ' ';
      }
      std::cout << std::endl;
  }
  ```

  

* 最大子数组和 [53. 最大子数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-subarray/description/)

  ```cpp
  #include <bits/stdc++.h>
  
  bool xis_max(int x, int y, int z) {
      return x >= y && x >= z;
  }
  
  auto find_crossing_subarray(const std::vector<int>& vec, int left, int mid, int right) -> std::tuple<int, int, int> {
      int sum = 0;
      int left_idx = left, right_idx = right;
      int left_sum = INT_MIN, right_sum = INT_MIN;
      for (int i = mid; i >= left; --i) {
          sum += vec[i];
          if (sum >= left_sum) {
              left_sum = sum;
              left_idx = i;
          }
      }
      sum = 0;
      for (int j = mid + 1; j <= right; ++j) {
          sum += vec[j];
          if (sum >= right_sum) {
              right_sum = sum;
              right_idx = j;
          }
      }
      return {left_idx, right_idx, left_sum + right_sum};
  }
  
  auto find_maximum_subarray(const std::vector<int>& vec, int left, int right) -> std::tuple<int, int, int> {
      if (left == right) {
          return {left, right, vec[left]};
      }
      int mid = left + ((right - left) >> 1);
      auto [left_low, left_high, left_sum] = find_maximum_subarray(vec, left, mid);
      auto [right_low, right_high, right_sum] = find_maximum_subarray(vec, mid + 1, right);
      auto [cross_low, cross_high, cross_sum] = find_crossing_subarray(vec, left, mid, right);
      if (xis_max(left_sum, right_sum, cross_sum)) {
          return {left_low, left_high, left_sum};
      } else if (xis_max(right_sum, left_sum, cross_sum)) {
          return {right_low, right_high, right_sum};
      } else {
          return {cross_low, cross_high, cross_sum};
      }
  }
  
  /**
   * @brief first=左边界 second=右边界 third=最大和
   */
  auto find_maximum_subarray(const std::vector<int>& vec) -> std::tuple<int, int, int> {
      return find_maximum_subarray(vec, 0, vec.size() - 1);
  }
  
  int main() {
      std::vector<int> arr = {1, -2, 4, 5, -2, 8, 3, -2, 6, 3, 7, -1};
      auto [max_low, max_high, max_sum] = find_maximum_subarray(arr);
      for(int i = max_low; i < max_high; ++i) {
          std::cout << arr[i] << ' ';
      }
      std::cout << std::endl;
      std::cout << max_sum << std::endl;
  }
  ```

  

## 6.2 搜索

* dfs本质上是n叉树前序遍历，bfs本质上是n叉树层序遍历

* 回溯时，相关量的改变在递归返回是需要撤销

* dfs可以用stack实现（或者说递归本来就是在运行栈运行），bfs可以用queue实现

* 特别的，lambda表达式可用于实现递归，相对来说较方便

* bfs

  ```cpp
  //bfs模板
  struct ed
  {
  	.....
  }
  deque<ed>q;
  void bfs()
  {
  	标记起点 
  	起点入队列 
  	while(!q.empty())//队列不为空 
  	{
  		ed nw=q.front();//返回队首
  		for(拓展出接下来可能的状态)
  		{
  			ed nxt;
  			记录这一状态
  			判断状态是否合法 
  			标记状态 
  			q.push_back(nxt);//状态入队列 
  		}
  		q.pop_front();//弹出队首 
  	}
  }
  ```

  

* [P1157 组合的输出 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1157)

  ```cpp
  #include <bits/stdc++.h>
  
  int n, r;
  
  void solve() {
      std::vector<int> path;
      std::function<void(int)> dfs = [&](int depth) {
          if(path.size() == r) {
              for(const auto& it : path) {
                  std::cout << std::setw(3) << it;
              }
              std::cout << std::endl;
              return;
          }
          for(int i = depth; i <= n; ++i) {
              path.push_back(i);
              dfs(i + 1);
              path.pop_back();
          }
      };
      dfs(1);
  }
  
  int main() {
      std::cin >> n >> r;
      solve();
  }
  ```

  

* [P1706 全排列问题 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1706)

  ```cpp
  #include <bits/stdc++.h>
  
  int n;
  
  void solve() {
      std::vector<bool> vis(n, false);
      std::vector<int> path;
      std::function<void(int)> dfs = [&](int depth) {
          if(depth == n) {
              for(const auto& num : path) {
                  std::cout << std::setw(5) << num;
              }
              std::cout << std::endl;
              return;
          }
          for(int i = 1; i <= n; ++i) {
              if(!vis[i]) {
                  path.push_back(i);
                  vis[i] = true;
                  dfs(depth + 1);
                  path.pop_back();
                  vis[i] = false;
              }
          }
      };
      dfs(0);
  }
  
  int main() {
      std::cin >> n;
      solve();
  }
  ```

  

* [P1605 迷宫 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1605)

  ```cpp
  #include <bits/stdc++.h>
  
  const int N = 10;
  int n, m, t, sx, sy, fx, fy;
  int mp[N][N];
  bool vis[N][N];
  
  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};
  
  int ans = 0;
  
  void dfs(int x, int y) {
      if(x == fx && y == fy) {
          ++ans;
          return;
      }
      for(int i = 0; i < 4; ++i) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] != 1) {
              vis[x][y] = true;
              dfs(nx, ny);
              vis[x][y] = false;
          }
      }
  }
  
  int main() {
      std::cin >> n >> m >> t >> sx >> sy >> fx >> fy;
      while(t--) {
          int x, y;
          std::cin >> x >> y;
          mp[x][y] = 1;
      }
      dfs(sx, sy);
      std::cout << ans << std::endl;
  }
  ```

  

* bfs [P1451 求细胞数量 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1451)

  ```cpp
  #include <bits/stdc++.h>
  
  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};
  
  int main() {
      int n, m;
      std::cin >> n >> m;
      std::vector<std::vector<int>> mp(n, std::vector<int>(m));
      for (int i = 0; i < n; ++i) {
          std::string str;
          std::cin >> str;
          for (int j = 0; j < m; ++j) {
              mp[i][j] = str[j] - '0';
          }
      }
  
      std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
      int ans = 0;
      auto bfs = [&](int x, int y) {
          std::queue<std::pair<int, int>> q;
          q.push({x, y});
          vis[x][y] = true;
          while(!q.empty()) {
              auto [rx, ry] = q.front();
              q.pop();
              for(int i = 0; i < 4; ++i) {
                  int nx = rx + dx[i];
                  int ny = ry + dy[i];
                  if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mp[nx][ny] != 0) {
                      vis[nx][ny] = true;
                      q.push({nx, ny});
                  }
              }
          }
      };
  
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
              if (mp[i][j] != 0 && !vis[i][j]) {
                  bfs(i, j);
                  ++ans;
              }
          }
      }
      std::cout << ans << std::endl;
  }
  ```

  

# **Chapter 7 数论**

## 模运算

模运算是大数运算中常见的操作，在算法竞赛中面对数据过大的时候，题目往往需要给出需要取模的要求，取模数一般为$1e9+7$、$1e9+9$、$998244353$。

这三个数比较大，但小于int32位最大值，并且三个数都是质数，至于为什么要质数，后面学习到其他算法会讲到。

定义取模运算为求$a$除以$m$的余数，记作：
$$
a \bmod m = a \% m
$$
一般的取余都是正整数的操作，对于负数求余数，不同的编译语言结果可能不同。

取模的性质：

加：$(a+b)\bmod m = ((a\bmod m)+(b \bmod m))\bmod m$

减：$(a-b)\bmod m = ((a\bmod m)-(b \bmod m))\bmod m$

乘：$(a*b) \bmod m = ((a\bmod m)*(b \bmod m))\bmod m$

对于除法取模是错误的，除法取模需要使用“逆”，在后续会讲到。

在运算过程中，对于大数相乘取模，会出现溢出的情况，即$a*b$或$(a\bmod m)*(b \bmod m)$可能会发生溢出。

此时我们可以不直接计算$a*b$，改为计算$(a*2*2……2*2)*(b/2/2……/2/2)$直到$b$减少为$0$为止。对于这种/2的操作我们可以采用二进制来处理。

但是如果$b$是奇数的话，$b/2$会取整，丢弃余数$1$，所以要判断$b$的奇偶性。

如果$b$是偶数就是$(a*2)*(b/2)$。

如果$b$是奇数就是$(a*2)*(b/2+1)=(a*2)*(b/2)+(a*2)$。

```c++
long long mul (long long a,long long b, long long m)
{
	a = a % m;
	b = b % m;
	long long res = 0;
	while(b > 0)
	{
		if(b & 1)//判断奇偶
			res = (res + a) % m;
		a = (a + a) % m;//a*2
		b >>=1;//b向右边移动一位，即去掉已经处理过的最后一位。
	}
	return res;
}
int main()
{
	long long a = 0x7877665544332211;
	long long b = 0x7988776655443322;
	long long m =  0x998776655443322;
    cout<<a*b%m<<'\n';//318333883276991760
	cout<<mul(a, b, m);//411509877096934416
}
```



## 快速幂

对于幂运算求$a^n$，如果我们直接一个一个的乘，时间复杂度为$O(n)$。如果使用快速幂，时间复杂度为$O(log_{2}{n})$。

快速幂标准做法采用位运算实现，下面介绍快速幂如何实现。

例如要计算$a^{11}$。我们可以分成$a^{11} = a^{8}*a^{2}*a^{1}$。其中$8、2、1$都是2的几次方，得出二进制为1101。

那么如何把$11$分解成$8+2+1$？把$n$按二进制处理即可。

遇到没有的幂次，我们进行判断一下跳过就可以了，比如$a^{11}$中没有$a^{4}$，检测到位为0，即可跳过。

[P1226 【模板】快速幂 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1226)

```cpp
long long fastpow(long long a,long long b,long long mod)
{
    long long ans = 1;
    a = a % mod;
    while(b)
    {
        if(b & 1)//检测最后一位是0还是1。
            ans = (ans * a) % mod;//如果是1，就乘以当前位数。
        a = (a * a) % mod;//递推a的次方。
        b >>= 1;//n向右边移动一位，即去掉已经处理过的最后一位。
    }
    return ans;
}
```



## GCD和LCM

最大公约数(GCD)和最小公倍数(LCM)是比赛中的高频考点。

### 整除

定义：$a$能整除$b$，记为$a|b$。其中，$a$、$b$为整数，且$a\neq b$，$b$是$a$的倍数。

性质:

1.若$a、b、c$为整数，且$a|b、b|c$，则$a|c$。

2.若$a、b、m、n$为整数，且$c|a、c|b$，则$c|(ma+nb)$；

### GCD

GCD的定义：整数$a$和整数$b$的最大公约数能同时整除$a$和$b$的最大整数，记为$gcd(a,b)$。

例如：$gcd(15,81) = 3，gcd(0,0)=0,gcd(0,3)=3,gcd(-6,-15)=3$。$-a$和$a$的因子相同，$gcd(a,b)=gcd(|a|,|b|)$所以我们在比赛中只考虑正整数的GCD。

### GCD的性质

1.$gcd(a,b) = gcd(a, a+b) = gcd(a,k*a+b)$

2.$gcd(ka,kb) = k * gcd(a,b)$

3.定义多个整数的GCD：$gcd(a,b,c) = gcd[gcd(a,b),c]$

4.若$gcd(a,b) = d$，则$gcd(a/d,b/d) = 1$,即$a/d$与$b/d$互素

5.$gcd(a+cb,b) = gcd(a,b)$

### 求GCD

求GCD常用方法有很多种，这里我只介绍两种较为重要的。

#### 1）欧几里得

即辗转相除法，$gcd(a,b)=gcd(b,a\bmod b)$。

下面给出证明：

设整数$a$和$b(a>b)$，则有$a = k*b+q$，其中$a、b、k、q$分别为被除数，除数，商和余数。

当$q$为$0$，显然$gcd(a,b)=k$为$k$。

当$q$不为$0$，设$a$和$b$最大公约数为$d$。则有$a = d*k_1$，$b=d*k_2$。

由$a = k*b+q$可以得到，$q = a-k*b=d*k_1-k*k_2*d=d(k_1-k*k_2)$。

可以看出$d$能整除$q$，所以$a$与$b$最大公约数等于$b$与$q$最大公约数。

反之我们也需要证明，即$a$和$b$的最大公约数就是$b$和$q$的最大公约数。上面证明，我们得出$d$是$q$的一个因子。

已知$q$是$b$和$d$的因子，那么$q$就可以整除$k*b+d$。此时$a=k*d+b$就可以得到$q$整除$a$。

所以$a、b$中任意一个公因数也必定是$b$、$q$的任意一个公因数，即$a、b$的公因数集等于$b、q$的公因数集。那么两个集合里的最大值也相等。

[B4025 最大公约数 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/B4025)****

```c++
int mygcd(int a,int b)//一直递归找gcd，回溯条件是b为0，此时可以得知gcd为a，因为gcd(a,0)=a。
{
	return b ? mygcd(b, a % b):a; 
}
```

另外，对于 C++17，我们可以使用[`<numeric>`](https://en.cppreference.com/w/cpp/numeric) 头中的 [`std::gcd`](https://en.cppreference.com/w/cpp/numeric/gcd) 与 [`std::lcm`](https://en.cppreference.com/w/cpp/numeric/lcm) 来求最大公约数和最小公倍数。

#### 2）更相减损术

即辗转相减法，由GCD的性质：$gcd(a,b)=gcd(b,a-b)=gcd(a,a-b)$。用大数减去小数，把所得的差与较小的数比较，继续减法，直到减数与差相等。

```c++
int mygcd(int a,int b)
{ r424 
	while(a != b)
	{
		if(a > b)
			a = a- b;
		else
			b = b- a;
	}
	return a;
}
```

更相减损术避免了欧几里得取模计算，但是计算次数更多。由于避免了取模操作，所以常用用于高精度计算GCD问题。

### LCM

$a$和$b$的最小公倍数表示为$lcm(a,b)$。

设$a=p_1^{c_1}p_2^{c_2}……p_m^{c_m}$，$b=p_1^{f_1}p_2^{f_2}……p_m^{f_m}$，则$gcd(a,b) = p_1^{min\{c_1,f_1\}}p_2^{min\{c_2,f_2\}}……p_m^{min\{c_3,f_3\}}$，$lcm(a,b) = p_1^{max\{c_1,f_1\}}p_2^{max\{c_2,f_2\}}……p_m^{max\{c_3,f_3\}}$。于是可以得出$gcd(a,b)lcm(a,b)=ab$。

注意要先除法后乘法，防止溢出。

```c++
int lcm(int a,int b)
{
	return a / gcd(a,b) * b;
}
```

### 裴蜀定理

定义：如果$a$与$b$都为整数，则有整数$x$和$y$使$ax+by=gcd(a,b)$。

推论：整数$a$与整数$b$互素当且仅当存在整数$x$和$y$，使$ax+by = 1$。

证明：使得$ax+by = d$，$d$一定是$gcd(a,b)$的整数倍。因为$a=gcd(a,b)*k_1，b=gcd(a,b)*k_2,ax+by=gcd(a,b)*k_1*x+gcd(a,b)*k_2*y=gcd(a,b)*(k_1+k_2+x+y)=d$。

所以最小的$d$是$gcd(a,b)$。

[P4549 【模板】裴蜀定理 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P4549)

```c++
#include <iostream>
using namespace std;
int a[100003];
long long gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}
int main ()
{
    int n;
    int i;
    cin>>n;
    for(i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    long long sum = 0;
    sum = gcd(abs(a[0]),abs(a[1]));
    for(i = 1;i < n;i++)
    {
        sum = gcd(abs(a[i]),sum);
    }
    cout<<sum;
}
```

### 二元线性丢番图方程

方程$ax + by = c$成为二元性丢番图方程，$x$和$y$是变量，其他是已知整数，问是否有整数解。

该方程是二维平面上的一条直线，如果直线上有整数坐标点，就有解，没有则无解，如果存在一个解就有无数个解。

**定理**：设$a$，$b$为整数且$gcd(a,b) = d$。如果$d$不能整除$c$，那么方程$ax + by = c$没有整数，否则存在无穷多个解。如果（${x_0}$，${y_0}$）是方程的一个特解，那么所有解可以表示为

$x = {x_0}+\frac{b}{d}*n$，

$y = {y_0}-\frac{a}{d}*n$,

$n$为任意整数。

例如：
（1）方程$18x + 3y = 7$没有整数解，因为$gcd(18, 3) = 3$，$3$不能整除$7$；
（2）方程$25x + 15y = 70$存在无穷个解，因为$gcd(25, 15) = 5$且$5$整除$70$，一个特解是$x_0= 4，y_0  = -2$，通解是$x = 4 + 3n，y = -2 - 5n$。

**证明**：令$a=da',b=db'$，有$ax+by=d(a'x+b'y)=c$。如果$x、y、a'、b'$是整数，那么$c$必须是$d$的整数倍数，才有整数解。

对于通解的形式，$x$值按$b/d$递增，$y$值按$-a/d$递增。我们可以设$(x_0,y_0)$是这条直线上的一个整数点，那么它移动到另一个点后的坐标为$(x_0+\Delta x,y_0+\Delta y)$。此时$\Delta x,\Delta y$必须是整数，$(x_0+\Delta x,y_0+\Delta y)$才是另一个整数点，我们知道这个直线必定通过原点，那么可以得到$a\Delta x+b\Delta y=0$。

那么$\Delta x$最小值是多少？因为$a/d$与$b/d$互素，只有$\Delta x=b/d，\Delta y =-a/d$时候，才为整数，并且满足$a\Delta x+b\Delta y=0$

### 扩展欧几里得

方程$ax+by=gcd(a,b)$，根据前一节的定理，它有整数解。扩展欧几里得算法求一个特解$(x_0,y_0)$。

下面证明为什么可以得到特解。

已知$ax+by=gcd(a,b)$,$bx'+(a\%b)y'=gcd(b,a\%b)$。

那么$ax+by=bx'+(a\%b)y'=bx'+(a-b(a/b)y')=ay'+b(x'-(a/b)y')$

所以可以得到$x=y',y=x'-(a/b)y'$。

递归终止条件$gcd(a,0) =a,$此时易知$x=1,y=0。

```c++
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b == 0)
    {
         x = 1;
         y = 0;
        return a;
    }
    long long d = exgcd(b, a%b,y,x);
    y -= a/b*x;
    return d;
}
```

#### 二元丢番图方程$ax+by=c$的解

用扩展欧几里德算法得到$ax+by=gcd(a,b)$的一个特解后，再利用它求方程$ax+by=c$的一个特解。步骤如下：
（1）判断方程$ax+by=c$是否有整数解，即$gcd(a,b)$能整除$c$ 。记 $d=gcd(a,b)$。

（2）用扩展欧几里得算法求$ax+by=d$的一个特解$ x_0，y_0$。

（3）在$ax_0 + by_0 = d$两边同时乘以$c/d$，得：$a x_0 c/d + b y_0 c/d = c$。

（4）对照$ax+by=c$，得到它的一个解$(x_0', y_0')$为：$x_0' = x_0 c / d$、$y_0' = y_0 c / d$。

（5）方程$ax + by = c$的通解：$ x=x_0' + (b/d)n$ ，$y=y_0' - (a/d)n$。 

已知通解为$x = x_0 + (b/d)n$要使$x$最小，则需要$x_0$不断的减$b/d$。那么此过程相当于取模，可以简单化为

$((x_0 \% (b/d)+b/d)\%(b/d))$ ，多加一次再去模防止负数。

[P1516 青蛙的约会 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1516)

```c++
#include <iostream>

using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
int main () {
    long long x, y, m, n, l;
    cin >> x >> y >> m >> n>>l;
    long long  c = x - y;
    long long a = n - m;
    if (a < 0) {
        a = -a;
        c = -c;
    }
    long long d = exgcd(a, l, x, y);
    if (c % d != 0)//判断方程有无整数解
        cout << "Impossible";
    else
        cout << ((x*c/d ) % (l / d) + (l / d)) % (l / d);
}
```

## 同余

设$m$是正整数，若$a$和$b$是整数，且$m|(a-b)$，则称$a$和$b$模$m$同余。即$a$除以$m$得到的余数和$b$除以$m$的余数相同，或者说$a-b$除以$m$，余数为$0$。

把$a$和$b$模$m$同余记为$a \equiv b(\bmod m)$，$m$称为同余的模。

### 一元线性同余方程

设$x$是未知数，给定$a、b、m$，求整数$x$，满足$ax \equiv b(\bmod m) $。

$ax \equiv b(\bmod m) $表示$ax - b$是$m$的倍数，设为$-y$倍，则有$ax+my=b$，这就是二元线性丢番图方程。所以求解一元线性同余方程等价于求解二元线性丢番图方程。

**定理**：设$a$、$b$和$m$是整数，$m > 0$，$gcd(a,m) = d$。若$d$不能整除$b$，则$ax \equiv b(\bmod m)$无解；若$d$能整除$b$，则$ax \equiv b(\bmod m)$有$d$个模$m$不同余的解。

此定理可以参考前面的线性丢番图方程来理解，如果有一个特解是$x_0$，那么通解是$x = x_0+(m/d)n$，当$n=0，1，2，……，d-1$时，有$d$个模$m$不同余的解。

**推论**：$a$和$m$互素时，因为$d =gcd(a,m) = 1$，所以线性同余方程$ax \equiv b(\bmod m)$有唯一的模$m$不同余的解。

### 逆

  给定整数a，且满足 $gcd(a,m)=1$，称$ax\equiv 1(\bmod m) $的一个解为 $a$模$m$的逆。记为$a^{-1}$。
  例如：$8x\equiv 1(\bmod 31)$，有一个解是$x = 4$，$4$是$8$模$31$的逆。所有的解，例如$35$、$66$等，都是$8$模$31$的逆。

​	  所以从逆的要求来看，$gcd(a,m)=1$可以看出，模$m$最好是一个大于$a$的素数，才能保证$gcd(a,m) = 1$。

#### 求逆

1）扩展欧几里得求逆

$ax \equiv 1(\bmod m)$，即丢番图方程$ax+my=1$，先用扩展欧几里得求$ax+my=1$的一个特解$x_0$，通解$x=x_0+mn$。然后通过取模计算最小整数解$((x_0 \bmod m) + m)\bmod m$。

```c++
#include <iostream>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b == 0)
    {
         x = 1;
         y = 0;
        return a;
    }
    long long d = exgcd(b, a%b,y,x);
    y -= a/b*x;
    return d;
}
int main ()
{
    long long a,b;
    long long y,x;
    cin>>a>>b;
    long long d = exgcd(a,b,x,y);

    cout<<(x % b + b) %b;
}
```

2）费马小定理求逆

设$n$是素数，$a$是正整数且与$n$互素，有$a^{n-1}\equiv 1(\bmod n)$。

$a*a^{n-2} \equiv 1(\mod n)$，那么$a^{n-2}\bmod n$，就是$a$模$n$的逆。

计算时候采用快速幂取模。

```c++
long long mod_inverse(long long a,long long mod)
{
	return fast_pow(a,mod - 2,mod);
}
```

#### 逆与除法取模

求$(a/b)\bmod m$，即使a除以b，然后对$m$取模。这里$a、b$都是很大的数，会溢出导致取模出错。用逆可以避免除法计算。

设$b$的逆元是$b^{-1}$，有$(a/b)\bmod m=((a/b) \bmod m)((bb^{-1}) \bmod m)=(a/b*bb^{-1})\bmod m=(ab^{-1})\bmod m$

除法的模运算转换为乘法模运算，即

$(a/b) \bmod m = (ab^{-1}) \bmod m =(a \bmod m)(b^{-1} \bmod m)\bmod m$



2024ICPC湖北省赛[Problem - J - Codeforces](https://codeforces.com/gym/105139/problem/J)

```c++
#include <bits/stdc++.h>
 
using namespace std;
long long m = 998244353;
long long fastpow(long long a,long long b,long long mod)
{
    long long ans = 1;
    a = a % mod;
    while(b)
    {
        if(b & 1)
        	ans = ans * a % mod;
   		a = a * a % mod;
    	b = b >> 1;
    }
    return ans;
}
long long a[1000003];
int main ()
{
	int n;
	long long sum = 0;
	int i;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
		sum +=a[i];
		sum = sum%m;
	}
	cout<<sum*fastpow(n,m - 2,m)%m;
    return 0;    
}
```

## 素数

定义：只能被1和自己整除的正整数。

### 素数判定

#### 1）试除法

时间复杂度$O(\sqrt{n})$，$n <=10^{12}$。

```cpp
bool is_prime(long long n)
{
	if(n <= 1)
		return false;
	for(long long i = 2;i<= sqrt(n);i++)//i*i<=n
	{
		if(n % i ==0)
			return false;
	}
    return true;
}
```



#### 2)Miller-Rabin素性测试



```c++
#include <bits/stdc++.h>

using namespace std;
long long fast_pow(long long x,long long y,int m)
{
	long long res = 1;
	x = x % m;
	while(y)
	{
		if(y&1)
			res = (res * x) % m;
		x = (x * x) % m;
		y >>= 1;
	}
	return res;
}
bool witness(long long a,long long b)//素性测试，返回true表示n是合数
{
	long long u = n - 1;//u是n-1的二进制去掉末尾0
	int t = 0;//n-1的二进制，是奇数u的二进制后面加t个0
	while(u&1 == 0)//整数n-1末尾0的个数就是t
	{
		u = u>>1;
		t++;
	}
	long long x1,x2;
	x1 = fast_pow(a,u,n);
	for(int i = 1;i <= t;i++) //平方取模
	{
		 x2 = fast_pow(x1,2,n);
		 if(x2 == 1&&x1 != 1&&x1 != n-1)
		 {
		 	return true;
		 }
		 x1 = x2;
	}
	if(x1 != -1)
		return true;//用费马测试判断是否为合数
	return false;
}
int miller_rabin(long long n,int s)
{
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n%2==0)
		return 0;
	for(int i = 0;i < s &&i < n;i++)//s次测试
	{
		long long a = rand()%(n-1) + 1; //a为随机数
		if(witness(a,n))
			return 0;
	}
	return 1;
}
int main()
{
	int m;
	cin>>m;
	int cnt = 0;
	for(int i = 0;i < m;i++)
	{
		long long n;
		cin>>n;
		int s = 50//50次测试
		cnt += miller_rabin(n,s);
	}
	cout<<cnt;
}
```

### 素数筛

给定$n$，求$2~n$内所有的素数。逐个判断时间复杂度非常高，我们可以筛法一起筛出所有整数，把非素数筛掉。

#### 埃式筛

时间复杂度$O(nlog_2log_2^{n})$

对于初始队列$\{2,3,4,5,6,7,8,9,10,11,12,13,……,n\}$。

(1)输出最小素数$2$，然后筛掉$2$的倍数，得$\{3,5,7,9,11,13……\}$。

(2)输出最小素数$3$，然后筛掉$3$的倍数，得$\{5,7,11,13,……\}$。

(3)输出最小素数$5$，然后筛掉$5$的倍数，得$\{7,11,13,……\}$。

```c++
const int N=1e7;
int prime[N+1];//储存素数
bool visit[N+1];//true表示被筛掉，不是素数
int E_sieve(int n)
{
    for(int i = 0;i <= n;i++)
    {
        visit[i] = false;//初始化为false
    }
    for(int i = 2;i * i <= n;i++)//遍历用来做筛除的数2、3、5
    {
        if(!visit[i])
        {
            for(int j = i*i;j <= n;j+=i)
            {
                visit[j] = true;//标记为非素数
			}
        }
    }
    int k =  0;//记录素数个数
    //上面筛完了，下面开始记录素数
    for(int i = 2;i <= n;i++)
    {
        if(!visit[i])
            prime[k++] = i;//把筛出来的素数存入数组中
    }
    return k;
}
```

埃式筛中做了一些无用功，某个数会被筛到好几次，比如$12$就被$2$和$3$筛了两次，所以我们就可以使用更快的欧式筛来改进。

#### 欧式筛

时间复杂度为$O(n)$。

一个合数肯定有一个最小质因数；让每个合数只被它的最小质因数筛选一次，达到不重复的目的。

[P3383 【模板】线性筛素数 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P3383)

```c++
int prime[N+1]; //保存素数
bool vis[N+1];//记录是否被筛
int euler_sieve(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(int i = 2;i <= n;i++)//检查每个数，筛去合数
	{
		if(!vis[i])
			prime[cnt++] = i;//如果没有被筛过，是素数，记录下来。
		for(int j = 0;j < cnt;j++)//用已经得到的素数去筛后面的数。
		{
			if(i * prime[j] > n) //只筛小于或等于n的数，大于直接退出
				break;
			vis[i * prime[j]] = 1;//用最小质因数筛去x
			if(i % prime[j] == 0)//如果i能整除它，表明i肯定不是x的最小质因数，
				break;
		}
	}
    return cnt;
}
```

代码vis[i*prime[j]] = 1中，表示用最小的质因数筛去了它的倍数，其中prime[j]是最小质因数。

后面一行中发现i能整除这个最小值质因数，那么可以说明i的最小是prime[j]，那么后面的prime[j+1]肯定不是最小质因数，于是可以退出循环了。比如当$i=4$时候，我们首先看$prime[j]=2$，筛去$8$，然后发现$i%prime[j]=0$，那么$prime[j+1]=3$就不会执行，因为$3*4=12$，而12的最小质因数是$2$，如果真的执行了，那么当$i=6$的时候，$prime[i]=2$，就会又执行一次，重复计算了。

### 质因数分解

前面我们讲LCM的时候提到了算术基本定理，即任何大于1的正整数$n$可以唯一分解为有限个素数的乘积：$n=p_1^{c_1}p_2^{c_2}……p_m^{c_m}$，其中$c_i$都为正整数，$p_i$都为素数且从小到大。我们可以通过这个定理来分解质因数。

#### 欧拉筛求最小质因数

我们知道欧拉筛是每次用最小质因数来操作，所以我们直接记录每次的最小质因数就可以了。

可以用来求$1-n$的每个数的最小质因数。

```cpp
int prime[N+1]; //保存素数
int vis[N+1];// 记录最小质因数
int euler_sieve(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(int i = 2;i <= n;i++)//检查每个数，筛去合数
	{
		if(!vis[i])
        {
			prime[cnt++] = i;//如果没有被筛过，是素数，记录下来。
        	vis[i] = i;//记录最小质因数
        }
        for(int j = 0;j < cnt;j++)//用已经得到的素数去筛后面的数。
		{
			if(i * prime[i] > n) //只筛小于或等于n的数，大于直接退出
				break;
			vis[i * prime[j]] = prime[j];//记录最小质因数
			if(i % prime[j] == 0)//如果i能整除它，表明i肯定不是x的最小质因数，
				break;
		}
	}
    return cnt;
}
```

### 试除法分解质因数

上面的欧拉筛是求最小质因数，分解质因数也可以采用试除法来求解。时间复杂度$O(\sqrt n)$

（1）首先检查$2-\sqrt n$的所有素数，如果他能整除$n$，就是最小质因数。然后连续的用$p_1$去除$n$。目的是为了去掉$n$中的$p_1$，从而得到$n_1$

（2）然后对于$n_1$，可以从$p_1-\sqrt n$来检查所有素数，和步骤1一样。因为我们找到了最小质因数$p_1$，所以$p_1$前面的数就没有必要检查了。

最后做完之后，如果剩下一个大于1的数，那么它也是一个素数，是$n$的最大质因数。

```c++
int p[20];//记录因数，p[1]为最小因数
int c[40];//记录第i个因数的个数，
int  factor(int n)
{
	int m = 0;
	for(int i = 2;i <= sqrt(n);i++)
	{
		if(n % i == 0)
		{
			p[++m] = i;//记录最小因数
			c[m] = 0;//初始化有0个此因数
			while(n % i== 0)//把n中重复的去掉
			{
				n = n / i;
				c[m]++;//去一次个数加1
			}
		}
	}
	if(n > 1)
	{
		p[++m] = n;
		c[m] = 1;
	}
	return m;
}
```

# **Chapter 8 动态规划**

## 8.1 dp基础

* dp问题具有最优子结构与重叠子问题
* 自上而下叫记忆化搜索，自下而上叫dp

## 8.2 线性dp

* [300. 最长递增子序列 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-increasing-subsequence/description/)
* [1143. 最长公共子序列 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-common-subsequence/)

## 8.3背包dp

### 8.3.1 01背包

* 模板题，网上随便找一道
* 当dp数组变为一维时，x格前面同一行的其他格都已经把原本y那一行的覆盖掉了，而x格从前面取的数值就可能会是更新过的，造成答案错误
* [416. 分割等和子集 - 力扣（LeetCode）](https://leetcode.cn/problems/partition-equal-subset-sum/)

### 8.3.2 完全背包

* 模板题，反转01背包容量遍历顺序即可重复

## 8.4 区间dp

* [P1880 [NOI1995\] 石子合并 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/problem/P1880)

