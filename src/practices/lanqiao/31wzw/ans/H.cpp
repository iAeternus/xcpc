#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
#include <cassert>

const int N = 1e5 + 3;
const int MOD = 1e9 + 7;
int n, sum;
int a[N];
std::vector<int> op; // 1 +; 2 -; 3 ^

int calc() {
	std::stack<int> st;
	int idx = 0;
	for(int i = 0; i < n; ++i) {
		st.push(a[i]);
		if(st.size() >= 2) {
			if(op[idx] == 3) {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num1 ^ num2);
			}
			++idx;
		}
	}
	
	std::vector<int> nn(st.size());
	for(int i = nn.size() - 1; i >= 0; --i) {
		if(!st.empty()) {
			nn[i] = st.top();
			st.pop();
		}
	}
	
//		std::cout << st.size() << std::endl;
//		assert(st.empty());
	
	int ans = nn[0], pos = 0;
	for(int i = 0; i < op.size(); ++i) {
		if(op[i] == 3) continue;
		if(op[i] == 1) { // +
			ans += nn[++pos];
		} else { // -
			ans -= nn[++pos];
		}
	}
	
	return ans;
}

void dfs() {
	if(op.size() == n - 1) {		
		sum = (sum + calc()) % MOD;
		return;
	}
	
	for(int i = 1; i <= 3; ++i) {
		op.push_back(i);
		dfs();
		op.pop_back();
	}
}

int main() {
	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	dfs();
	std::cout << sum << std::endl;
}
