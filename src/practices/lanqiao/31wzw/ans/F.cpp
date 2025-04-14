#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

typedef long long i64;

int find(const std::string& s) {
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == '#') {
			return i;
		}
	}
	return -1;
}

int main() {
	std::string f, s;
	std::cin >> f >> s;
	int n = f.length();
	
	int start1 = find(f);
	int start2 = find(s);
	if(start1 == -1 && start2 == -1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	
	int start = std::min(start1, start2);
	int cnt1 = 0, cnt2 = 0;
	for(int i = start; i < n; ++i) {
		if(f[i] == '.') {
			++cnt1;
		}
		if(s[i] == '.') {
			++cnt2;
		}
	}
	
	std::cout << std::min(cnt1, cnt2) << std::endl;
	
	return 0;
}
