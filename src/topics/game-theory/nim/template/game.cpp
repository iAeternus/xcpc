#include <bits/stdc++.h>

int xorSum(const std::vector<int>& nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sum ^= nums[i];
    }
    return sum;
}

int getBit(int num, int i) {
    return num >> i & 1;
}

int lowbit(int x) {
    return x & -x;
}

int reverse(int x) {
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x & 0x0f0f0f0f) << 4);
    x = ((x >> 8) & 0x00ff00ff) | ((x & 0x00ff00ff) << 8);
    x = ((x >> 16) & 0x0000ffff) | ((x & 0x0000ffff) << 16);
    return x;
}

int highBit(int x) {
    return reverse(lowbit(reverse(x)));
}

int highBitCount(int x) {
    return log2(highBit(x));
}

bool victoryChoice(std::vector<int>& nums) {
    int s = xorSum(nums);
    int h = highBitCount(s);
    for (auto& num : nums) {
        if (getBit(num, h)) {
            num ^= s;
            return true;
        }
    }
    return false;
}

void randomChoice(std::vector<int>& nums) {
    int i = rand() % nums.size();
    nums[i] -= (rand() % nums[i]);
}

void play(std::vector<int>& nums) {
    if (victoryChoice(nums)) {
        return;
    }
    randomChoice(nums);
}

void play2(std::vector<int>& nums) {
    int s = xorSum(nums);
    for (auto& num : nums) {
        if ((num ^ s) < num) {
            num ^= s;
            break;
        }
    }
}

void printVector(const std::vector<int>& nums) {
    for (const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}

bool isWin(const std::vector<int>& nums) {
    for (const auto& num : nums) {
        if (num) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 6};
    play(nums);
    printVector(nums);

    std::vector<int> nums2 = {5, 7, 9};
    while (!isWin(nums2)) {
        play2(nums2);
        printVector(nums2);
    }
}