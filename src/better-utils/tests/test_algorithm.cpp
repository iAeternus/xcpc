#include "test_algorithm.h"
#include "test_utils.h"
#include "Algorithm.h"

#include <cassert>

auto should_linear_search = []() {
    // Given
    std::size_t n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};

    // When
    std::size_t res1 = Algorithm::linearSearch(arr1, n, 3);
    std::size_t res2 = Algorithm::linearSearch(arr1, n, 6);
    std::size_t res3 = Algorithm::linearSearch(arr2, n, 'a');
    std::size_t res4 = Algorithm::linearSearch(arr2, n, 'e');
    std::size_t res5 = Algorithm::linearSearch(arr2, n, 'f');

    // Then
    assert(res1 == 2);
    assert(res2 == n);
    assert(res3 == 0);
    assert(res4 == 4);
    assert(res5 == n);
};

auto should_binary_search = []() {
    // Given
    std::size_t n = 6;
    int arr1[] = {1, 2, 3, 3, 4, 5};
    char arr2[] = {'a', 'a', 'b', 'c', 'd', 'e'};

    // When
    std::size_t res1 = Algorithm::binarySearch(arr1, n, 3);
    std::size_t res2 = Algorithm::binarySearch(arr1, n, 6);
    std::size_t res3 = Algorithm::binarySearch(arr2, n, 'a');
    std::size_t res4 = Algorithm::binarySearch(arr2, n, 'e');
    std::size_t res5 = Algorithm::binarySearch(arr2, n, 'f');

    // Then
    assert(res1 == 2);
    assert(res2 == n);
    assert(res3 == 0);
    assert(res4 == 5);
    assert(res5 == n);
};

void test_algorithm() {
    TestUtils::UnitTestGroup group("Algorithm Test");

    group.addTest(TestUtils::UnitTest("should_linear_search", should_linear_search));
    group.addTest(TestUtils::UnitTest("should_binary_search", should_binary_search));

    group.startAll();
}