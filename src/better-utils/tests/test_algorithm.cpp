#include "test_algorithm.h"
#include "test_utils.h"
#include "Algorithm.h"

#include <cassert>

auto should_linear_search = []() {
    // Given
    int n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};

    // When
    std::size_t res1 = Algorithm::linearSearch<int>(arr1, n, 3);
    std::size_t res2 = Algorithm::linearSearch<int>(arr1, n, 6);
    std::size_t res3 = Algorithm::linearSearch<char>(arr2, n, 'a');
    std::size_t res4 = Algorithm::linearSearch<char>(arr2, n, 'f');

    // Then
    assert(res1 = 2);
    assert(res2 = -1);
    assert(res3 = 0);
    assert(res4 = -1);
};

void test_algorithm() {
    TestUtils::UnitTestGroup group("Algorithm Test");

    group.addTest(TestUtils::UnitTest("should_linear_search", should_linear_search));

    group.startAll();
}