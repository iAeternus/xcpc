#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

typedef long long i64;
const int MOD = 1e9 + 7;

int fact(int n) {
	i64 ans = 1;
	for(int i = 2; i <= n; ++i) {
		ans = (ans * i) % MOD;
	}
	return ans;
}

int main() {
//	assert(2023 * 2025 <= 2021 * 2025 + 2025);
//	int mul = 1;
//	for(int i = 2024; i >= 1; --i) {
////		mul = (mul * (2026 - i)) % MOD;
//		
//		mul = (mul % MOD * (2026LL - i) % MOD) % MOD;
//	}
//	std::cout << mul << std::endl;
	std::cout << fact(2025) << std::endl;
}
