#include <bits/stdc++.h>

/**
 * 在单调增的数组中查找target或target的后继
 */
int bin_search(int* a, int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

/**
 * 在单调增的数组中查找target或target的前驱
 */
int bin_search2(int* a, int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (a[mid] <= target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    // Given
    int a[] = {0, 1, 1, 2, 2, 4, 4, 4};
    int n = 8;

    int target = 3;

    // When
    int idx1 = bin_search(a, n, target);
    int idx2 = bin_search2(a, n, target);

    // Then
    std::cout << idx1 << std::endl;
    std::cout << idx2 << std::endl;
}