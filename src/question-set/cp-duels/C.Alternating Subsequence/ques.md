# Alternating Subsequence

## 题面翻译

给定一个由非零整数构成的序列，求出其满足以下条件的子序列中，各项之和最大的：
- 相邻两项异号
- 长度最大

输出这个最大的和。

**每个测试点均有多组数据**

## 题目描述

Recall that the sequence $ b $ is a a subsequence of the sequence $ a $ if $ b $ can be derived from $ a $ by removing zero or more elements without changing the order of the remaining elements. For example, if $ a=[1, 2, 1, 3, 1, 2, 1] $ , then possible subsequences are: $ [1, 1, 1, 1] $ , $ [3] $ and $ [1, 2, 1, 3, 1, 2, 1] $ , but not $ [3, 2, 3] $ and $ [1, 1,       1, 1, 2] $ .

You are given a sequence $ a $ consisting of $ n $ positive and negative elements (there is no zeros in the sequence).

Your task is to choose maximum by size (length) alternating subsequence of the given sequence (i.e. the sign of each next element is the opposite from the sign of the current element, like positive-negative-positive and so on or negative-positive-negative and so on). Among all such subsequences, you have to choose one which has the maximum sum of elements.

In other words, if the maximum length of alternating subsequence is $ k $ then your task is to find the maximum sum of elements of some alternating subsequence of length $ k $ .

You have to answer $ t $ independent test cases.

## 输入格式

The first line of the input contains one integer $ t $ ( $ 1       \le t \le 10^4 $ ) — the number of test cases. Then $ t $ test cases follow.

The first line of the test case contains one integer $ n $ ( $ 1 \le n \le 2 \cdot 10^5 $ ) — the number of elements in $ a $ . The second line of the test case contains $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ -10^9 \le a_i \le 10^9,       a_i \ne 0 $ ), where $ a_i $ is the $ i $ -th element of $ a $ .

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ ( $ \sum n \le 2 \cdot 10^5 $ ).

## 输出格式

For each test case, print the answer — the maximum sum of the maximum by size (length) alternating subsequence of a.

## 样例 #1

### 样例输入 #1

```
4
5
1 2 3 -1 -2
4
-1 -2 -1 -3
10
-2 8 3 8 -4 -15 5 -2 -3 1
6
1 -1000000000 1 -1000000000 1 -1000000000
```

### 样例输出 #1

```
2
-1
6
-2999999997
```

## 提示

In the first test case of the example, one of the possible answers is $ [1, 2, \underline{3}, \underline{-1}, -2] $ .

In the second test case of the example, one of the possible answers is $ [-1, -2, \underline{-1}, -3] $ .

In the third test case of the example, one of the possible answers is $ [\underline{-2}, 8, 3, \underline{8},       \underline{-4}, -15, \underline{5}, \underline{-2}, -3, \underline{1}] $ .

In the fourth test case of the example, one of the possible answers is $ [\underline{1}, \underline{-1000000000},       \underline{1}, \underline{-1000000000}, \underline{1}, \underline{-1000000000}] $ .