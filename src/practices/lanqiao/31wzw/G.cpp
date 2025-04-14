/*
9
9 7 3 7 1 6 2 2 7
1 2
1 3
2 4
2 5
2 6
6 7
6 8
6 9
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

const int N = 1e3 + 5;

struct Node {
	int v, w;
};

std::vector<Node> adj[N];

void addEdge(int u, int v, int w) {
	adj[u].push_back({v, w});
}

bool cmp(const Node& o1, const Node& o2) {
	return o1.w < o2.w;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> w(n);
	for(int i = 0; i < n; ++i) {
		std::cin >> w[i];
	}
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		addEdge(u, v, w[v]);
		addEdge(v, u, w[v]);
	}
	
	for(int i = 0; i < n; ++i) {
		std::sort(adj[i].begin(), adj[i].end(), cmp);
	}
	
	std::queue<Node> q;
	int ans = 0;
	while(!q.empty()) {
		Node x = q.front();
		q.pop();
		int sum_w = 0;
		for(int i = 0; i < adj[x.v].size(); ++i) {
			q.push({i, w[i]});
			sum_w += w[i];
		}
		
		int pos = 0;
		while(sum_w > x.w) {
			sum_w -= adj[x.v][pos++].w;
		}
		ans += sum_w;
	}
	
	std::cout << ans << std::endl;
}
