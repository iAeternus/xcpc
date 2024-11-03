/**
 * @brief 二叉搜索树
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinarySearchTreeNode.h"

template<typename T, typename C = std::less<T>()>
class BinarySearchTree {
public:
    BinarySearchTree(BinarySearchTreeNode<T>* root = nullptr);
    ~BinarySearchTree();

    constexpr std::size_t getSize() const;

    void insert(const T& value);
    void insert(T&& value);
    void remove(const T& value);
private:
    std::unique_ptr<BinarySearchTreeNode<T>> root;
    std::size_t size;
};

#endif // BINARY_SEARCH_TREE_H