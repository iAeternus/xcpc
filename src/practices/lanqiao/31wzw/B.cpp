#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long i64;
const int MOD = 1e9 + 7;
std::vector<int> v(2025);

bool check() {
	for(int i = 0; i < 2025; ++i) {
		for(int j = 0; j < 2025; ++j) {
			if(v[i] * v[j] > (i + 1) * (j + 1) + 2025) {
				return false;
			}
		}
	}
	return true;	
}

int main() {
	for(int i = 0; i < 2025; ++i) {
		v[i] = i + 1;
	}
	
	int cnt = 0;
	do {
//        for(int i = 0; i < v.size(); ++i) {
//        	std::cout << v[i] << ' ';
//		}
//		std::cout << std::endl;
		if(check()) {
			cnt = (cnt + 1) % MOD;
		}
    } while(std::next_permutation(v.begin(), v.end()));
    std::cout << cnt << std::endl;
	return 0;
}


