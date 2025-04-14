#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

typedef long long i64; 

void solve() {
	i64 a, b, c, k;
	std::cin >> a >> b >> c >> k;
	while(k--) {
		i64 na = (b + c) >> 1;
		i64 nb = (a + c) >> 1;
		i64 nc = (a + b) >> 1;
		a = na;
		b = nb;
		c = nc;
	}
	std::cout << a << ' ' << b << ' ' << c << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	
	while(t--) {
		solve();
	}
}
