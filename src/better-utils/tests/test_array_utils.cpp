#include "test_array_utils.h"
#include "test_utils.h"
#include "ArrayUtils.h"

#include <cassert>
#include <iostream>

auto should_linear_search = []() {
    // Given
    std::size_t n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};

    // When
    int* res1 = ArrayUtils::linearSearch(arr1, arr1 + n, 3);
    int* res2 = ArrayUtils::linearSearch(arr1, arr1 + n, 6);
    char* res3 = ArrayUtils::linearSearch(arr2, arr2 + n, 'a');
    char* res4 = ArrayUtils::linearSearch(arr2, arr2 + n, 'e');
    char* res5 = ArrayUtils::linearSearch(arr2, arr2 + n, 'f');

    // Then
    TestUtils::Assertions::assertEquals<int>(2, ArrayUtils::getSize(arr1, res1));
    TestUtils::Assertions::assertNull<int>(res2);
    TestUtils::Assertions::assertEquals<char>(0, ArrayUtils::getSize(arr2, res3));
    TestUtils::Assertions::assertEquals<char>(4, ArrayUtils::getSize(arr2, res4));
    TestUtils::Assertions::assertNull<char>(res5);
};

auto should_binary_search = []() {
    // Given
    std::size_t n = 6;
    int arr1[] = {1, 2, 3, 3, 4, 5};
    char arr2[] = {'a', 'a', 'b', 'c', 'd', 'e'};

    // When
    auto res1 = ArrayUtils::binarySearch(arr1, arr1 + n, 3);
    auto res2 = ArrayUtils::binarySearch(arr1, arr1 + n, 6);
    auto res3 = ArrayUtils::binarySearch(arr2, arr2 + n, 'a');
    auto res4 = ArrayUtils::binarySearch(arr2, arr2 + n, 'e');
    auto res5 = ArrayUtils::binarySearch(arr2, arr2 + n, 'f');

    // Then   
    TestUtils::Assertions::assertEquals<int>(2, ArrayUtils::getSize(arr1, res1));
    TestUtils::Assertions::assertNull(res2);
    TestUtils::Assertions::assertEquals<char>(0, ArrayUtils::getSize(arr2, res3));
    TestUtils::Assertions::assertEquals<char>(5, ArrayUtils::getSize(arr2, res4));
    TestUtils::Assertions::assertNull(res5);
};

void test_array_utils() {
    TestUtils::UnitTestGroup group("ArrayUtils Test");

    group.addTest(TestUtils::UnitTest("should_linear_search", should_linear_search));
    group.addTest(TestUtils::UnitTest("should_binary_search", should_binary_search));

    group.startAll();
}