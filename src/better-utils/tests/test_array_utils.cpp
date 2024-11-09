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

static constexpr std::size_t MIN_N = 1e3;
static constexpr std::size_t MAX_N = 1e4;
static constexpr std::size_t LOWER = 1e3;
static constexpr std::size_t UPPER = 1e4;

auto should_insertion_sort = []() {
    // Given
    std::size_t n = TestUtils::rnd.nextInt(MIN_N, MAX_N);
    int* arr = TestUtils::rnd.nextIntArray(n, LOWER, UPPER);

    // When
    ArrayUtils::insertionSort(arr, arr + n);

    // Then
    TestUtils::Assertions::assertAcsOrder(arr, arr + n);

    // When
    ArrayUtils::insertionSort<int>(arr, arr + n, std::greater<int>{});

    // Then
    TestUtils::Assertions::assertDescOrder(arr, arr + n);

    // Final
    delete[] arr;
};

auto should_shell_sort = []() {
    // Given
    std::size_t n = TestUtils::rnd.nextInt(MIN_N, MAX_N);
    int* arr = TestUtils::rnd.nextIntArray(n, LOWER, UPPER);

    // When
    ArrayUtils::shellSort(arr, arr + n);

    // Then
    TestUtils::Assertions::assertAcsOrder(arr, arr + n);

    // When
    ArrayUtils::shellSort<int>(arr, arr + n, std::greater<int>{});

    // Then
    TestUtils::Assertions::assertDescOrder(arr, arr + n);

    // Final
    delete[] arr;
};

auto should_selection_sort = []() {
    // Given
    std::size_t n = TestUtils::rnd.nextInt(MIN_N, MAX_N);
    int* arr = TestUtils::rnd.nextIntArray(n, LOWER, UPPER);

    // When
    ArrayUtils::selectionSort(arr, arr + n);

    // Then
    // TestUtils::printArray(arr, arr + n);
    TestUtils::Assertions::assertAcsOrder(arr, arr + n);

    // When
    // TestUtils::printArray(arr, arr + n);
    ArrayUtils::selectionSort<int>(arr, arr + n, std::greater<int>{});

    // Then
    TestUtils::Assertions::assertDescOrder(arr, arr + n);

    // Final
    delete[] arr;
};

auto should_heap_sort = []() {
    // Given
    std::size_t n = TestUtils::rnd.nextInt(MIN_N, MAX_N);
    int* arr = TestUtils::rnd.nextIntArray(n, LOWER, UPPER);

    // When
    ArrayUtils::heapSort(arr, arr + n);

    // Then
    // TestUtils::printArray(arr, arr + n);
    TestUtils::Assertions::assertAcsOrder(arr, arr + n);

    // When
    // TestUtils::printArray(arr, arr + n);
    ArrayUtils::heapSort<int>(arr, arr + n, std::greater<int>{});

    // Then
    TestUtils::Assertions::assertDescOrder(arr, arr + n);

    // Final
    delete[] arr;
};

void test_array_utils() {
    TestUtils::UnitTestGroup group("ArrayUtils Test");

    group.addTest(TestUtils::UnitTest("should_linear_search", should_linear_search));
    group.addTest(TestUtils::UnitTest("should_binary_search", should_binary_search));
    group.addTest(TestUtils::UnitTest("should_insertion_sort", should_insertion_sort));
    group.addTest(TestUtils::UnitTest("should_shell_sort", should_shell_sort));
    // group.addTest(TestUtils::UnitTest("should_selection_sort", should_selection_sort));
    group.addTest(TestUtils::UnitTest("should_heap_sort", should_heap_sort));

    group.startAll();
}