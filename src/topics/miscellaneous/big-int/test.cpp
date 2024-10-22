#include <cassert>
#include <iostream>

#include "BigInteger.h"

void test_basic() {
    std::string a = "12345678";
    BigInteger b;
    while (!a.empty()) {
        b.push(a.back() - '0');
        a.pop_back();
    }
    for (auto& it : b) {
        std::cout << it;
    }
    std::cout << std::endl;
    std::cout << *b.end() << std::endl;
    std::cout << *b.rend() << std::endl;
    std::cout << *b.cend() << std::endl;
    std::cout << *b.crend() << std::endl;
    for (auto it = b.begin(); it != b.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    for (auto it = b.rbegin(); it != b.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    for (auto it = b.cbegin(); it != b.cend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    for (auto it = b.crbegin(); it != b.crend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    while (!b.empty()) {
        std::cout << b << ' ' << b.front() << std::endl;
        b.pop();
    }
}

void test_operates() {
    // Given
    BigInteger a = "20000000000000000000000000001";
    BigInteger b = "10000000000000000000000000000";

    // When
    BigInteger r1 = a + b;
    BigInteger r2 = a - b;
    BigInteger r3 = a * b;
    BigInteger r4 = a / b;
    BigInteger r5 = a % b;

    // Then
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;
    std::cout << r4 << std::endl;
    std::cout << r5 << std::endl;
    assert(r1 == BigInteger("30000000000000000000000000001"));
    assert(r2 == BigInteger("10000000000000000000000000001"));
    assert(r3 == BigInteger("200000000000000000000000000010000000000000000000000000000"));
    assert(r4 == BigInteger("2"));
    assert(r5 == BigInteger("1"));
}

void test_conversion() {
    // Given
    BigInteger a = "1024", b = "0";

    // When
    long long r1 = (long long)a;
    std::string r2 = std::string(a);
    bool r3 = (bool)a;
    bool r4 = (bool)b;

    // Then
    assert(r1 == 1024);
    assert(r2 == "1024");
    assert(r3 == true);
    assert(r4 == false);
}

void test_pow() {
    // Given
    BigInteger a(2);
    long long n = 1000;

    // When
    BigInteger r = a.pow(n);

    // Then
    std::cout << r << std::endl;
}

int main() {
    // test_basic();
    test_operates();
    test_conversion();
    // test_pow();
}