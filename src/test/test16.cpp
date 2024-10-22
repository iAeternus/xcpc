#include <bits/stdc++.h>

std::size_t nextSize(std::size_t size) {
    if(size < 16) {
        return 16;
    } else if((size & (size - 1)) == 0) {
        return size;
    }

    std::size_t nextPowerOfTwo = 1;
    while (nextPowerOfTwo <= size) {
        nextPowerOfTwo <<= 1;
    }
    return nextPowerOfTwo;
}

int main() {
    int size;
    std::cin >> size;
    std::cout << nextSize(size) << std::endl;
}