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
int dp[N][N];

void addEdge(int u, int v, int w) {
	adj[u].push_back({v, w});
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
	
//	std::cout << 8 << std::endl;

	for(int i = 0; i < n; ++i) {
		if(adj[i].empty()) {
			dp[i][w[i]] = w[i];
		}
	}
	
	std::queue<Node> q;
	q.push({0, w[0]});
	while(!q.empty()) {
		Node node = q.front();
		q.pop();
//		std::cout << node.v << std::endl;
		for(int i = 0; i < adj[node.v].size(); ++i) { // wuping
			q.push({i, w[i]});
			for(int j = node.w; j >= w[i]; --j) { // rongliang
				if(dp[i][j - w[i]] + w[i] <= node.w) {
					dp[node.v][j] = std::max(dp[i][j], dp[i][j - w[i]] + w[i]);
				}
			}
		}
	}
	
//	for(int i = 0; i < n; ++i) {
//		for(int j = 0; j < n; ++j) {
//			std::cout << dp[i][j] << ' ';
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
	
	std::cout << dp[0][w[0]] << std::endl;
}







