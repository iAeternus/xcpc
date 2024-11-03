#include <bits/stdc++.h>

template<typename T>
T* binarySearch(T* arrBegin, T* arrEnd, const T& target) {
    T* left = arrBegin;
    T* right = arrEnd - 1;
    while(left <= right) {
        T* mid = left + ((right - left) >> 1L);
        if(*mid < target) {
            left = mid + 1;
        } else if(*mid > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return nullptr;
}

int main() {
    int n = 6;
    int a[] = {1, 1, 2, 3, 4, 5};
    std::cout << binarySearch(a, a + n, 1) - a << std::endl;
    std::cout << binarySearch(a, a + n, 3) - a << std::endl;
    std::cout << binarySearch(a, a + n, 6) << std::endl;
}