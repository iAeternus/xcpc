#include "test_utils.h"
#include "test_binary_search_tree.h"

auto should_create_binary_search_tree = []() {
    
};

void test_binary_search_tree() {
    TestUtils::UnitTestGroup group("Binary Search Tree Test");

    group.addTest(TestUtils::UnitTest("should_create_binary_search_tree", should_create_binary_search_tree));

    group.startAll();
}