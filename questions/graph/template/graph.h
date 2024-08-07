#ifndef GRAPH_H
#define GRAPH_H

#include <functional>

using ll = long long;
using WEIGHT = int;  // 边权类型
using POINT = int;   // 点权类型

#define INF 0x7fffffff  // 最大权值

const int N = 1e5 + 5;  // 最大点数
const int M = N << 1;   // 最大边数

extern POINT head[N];  // 点集
extern int cnt;        // cnt记录当前存储位置

extern struct Edge {
    int from;  // 边的起点
    int to;    // 边的终点
    int next;  // 起点的下一个邻居
    WEIGHT w;  // 边权
} edge[M];     // 边集

/**
 * 初始化图
 */
void init();

/**
 * 添加边
 */
void add_edge(int u, int v, WEIGHT w);

/**
 * 遍历给定节点的所有邻居
 */
void for_each(int u, const std::function<void(int)>& func);

extern bool vis[N];  // visit数组

/**
 * 从给定节点开始深搜
 */
void dfs(int u, const std::function<void(int)>& func);

/**
 * 从给定节点开始广搜
 */
void bfs(int u, const std::function<void(int)>& func);

/**
 * 最短路 dijkstra --存在问题
 */
WEIGHT dijkstra(int s, int t);

/**
 * 最短路 SPFA算法
 * 原始版本：适合有负权边的图或边数较少的图
 */
WEIGHT SPFA(int s, int t);

/**
 * 最短路 SPFA算法
 * SLF优化：使用双端队列优化，设从u拓展出了v、队首元素k，如果dist[v]<dist[k]，则将v加
 * 入队首，否则加入队尾
 */
WEIGHT SPFA_SLF(int s, int t);

/**
 * 最短路 SPFA算法 --存在问题
 * LLL优化：设队首元素为k，每次松弛时加入判断，设队列中所有dist的平均值为x，若dist[k]>x，
 * 则将k移到队尾，查找下一个元素；直到使得dist[k]≤x再进行松弛
 */
WEIGHT SPFA_LLL(int s, int t);

#endif  // GRAPH_H