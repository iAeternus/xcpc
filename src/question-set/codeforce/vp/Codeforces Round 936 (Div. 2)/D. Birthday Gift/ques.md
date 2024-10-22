# Birthday Gift

## 题面翻译

有 $t$ 组数据。每组数据第一行给出两个整数 $n$ 和 $x$，接下来是一个长度为 $n$ 的序列 $a$。

对于每一组数据，输出最大的 $k$ 使得整个序列 $a$ 可以被分成 $k$ 个区间 $[l_1,r_1],[l_2,r_2],[l_3,r_3],...[l_k,r_k]$，满足：

- $l_1=1$，$r_k=n$。
- 对于任意 $1\le i\le k$，$l_i\le r_i$。
- 对于任意 $1\le i<k$，$r_i+1=l_{i+1}$。
- $(a_{l_1}\oplus a_{l_1+1}\oplus ...\oplus a_{r_1})|(a_{l_2}\oplus a_{l_2+1}\oplus ...\oplus a_{r_2})|...|(a_{l_k}\oplus a_{l_k+1}\oplus ...\oplus a_{r_k})\le x$

## 题目描述

Yarik's birthday is coming soon, and Mark decided to give him an array $ a $ of length $ n $ .

Mark knows that Yarik loves bitwise operations very much, and he also has a favorite number $ x $ , so Mark wants to find the maximum number $ k $ such that it is possible to select pairs of numbers \[ $ l_1, r_1 $ \], \[ $ l_2, r_2 $ \], $ \ldots $ \[ $ l_k, r_k $ \], such that:

- $ l_1 = 1 $ .
- $ r_k = n $ .
- $ l_i \le r_i $ for all $ i $ from $ 1 $ to $ k $ .
- $ r_i + 1 = l_{i + 1} $ for all $ i $ from $ 1 $ to $ k - 1 $ .
- $ (a_{l_1} \oplus a_{l_1 + 1} \oplus \ldots \oplus a_{r_1}) | (a_{l_2} \oplus a_{l_2 + 1} \oplus \ldots \oplus a_{r_2}) | \ldots | (a_{l_k} \oplus a_{l_k + 1} \oplus \ldots \oplus a_{r_k}) \le x $ , where $ \oplus $ denotes the operation of [bitwise XOR](https://en.wikipedia.org/wiki/Exclusive_or), and $ | $ denotes the operation of [bitwise OR](https://en.wikipedia.org/wiki/Logical_disjunction).

If such $ k $ does not exist, then output $ -1 $ .

## 输入格式

Each test consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \le t \le 10^4 $ ) — the number of test cases. The following lines contain the descriptions of the test cases.

The first line of each test case contains two integers $ n $ and $ x $ ( $ 1 \le n \le 10^5, 0 \le x < 2^{30} $ ) — the length of the array $ a $ and the number $ x $ respectively.

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ 0 \le a_i < 2^{30} $ ) — the array $ a $ itself.

It is guaranteed that the sum of the values of $ n $ across all test cases does not exceed $ 10^5 $ .

## 输出格式

For each test case, output a single integer on a separate line — the maximum suitable number $ k $ , and $ -1 $ if such $ k $ does not exist.

## 样例 #1

### 样例输入 #1

```
8
3 1
1 2 3
2 2
1 1
2 2
1 3
2 3
0 0
3 2
0 0 1
4 2
1 3 3 7
2 2
2 3
5 0
0 1 2 2 1
```

### 样例输出 #1

```
2
2
1
2
3
-1
1
2
```

## 提示

In the first test case, you can take $ k $ equal to $ 2 $ and choose two segments \[ $ 1, 1 $ \] and \[ $ 2, 3 $ \], $ (1) | (2 \oplus 3) = 1 $ . It can be shown that $ 2 $ is the maximum possible answer.

In the second test case, the segments \[ $ 1, 1 $ \] and \[ $ 2, 2 $ \] are suitable, $ (1) | (1) = 1 $ . It is not possible to make more segments.

In the third test case, it is not possible to choose $ 2 $ segments, as $ (1) | (3) = 3 > 2 $ , so the optimal answer is $ 1 $ .