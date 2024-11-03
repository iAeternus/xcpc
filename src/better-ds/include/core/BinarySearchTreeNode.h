/**
 * @brief 二叉搜索树节点
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

#include <functional>
#include <memory>

template<typename T>
class BinarySearchTreeNode {
public:
    BinarySearchTreeNode(const T& value, BinarySearchTreeNode* leftChild = nullptr, BinarySearchTreeNode* rightChild = nullptr);
    BinarySearchTreeNode(T&& value, BinarySearchTreeNode* leftChild = nullptr, BinarySearchTreeNode* rightChild = nullptr);
    ~BinarySearchTreeNode();

    T getValue() const;
    void setValue(const T& value);
    void setValue(T&& value);
private:
    std::unique_ptr<T> valuePtr;
    std::unique_ptr<BinarySearchTreeNode> leftChildPtr;
    std::unique_ptr<BinarySearchTreeNode> rightChildPtr;
};

template<typename T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T& value, BinarySearchTreeNode* leftChild, BinarySearchTreeNode* rightChild) : 
        value(std::make_unique<T>(value)), leftChild(std::make_unique<BinarySearchTreeNode>(leftChild)), rightChild(std::make_unique<BinarySearchTreeNode>(rightChild)) {}

template<typename T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(T&& value, BinarySearchTreeNode* leftChild, BinarySearchTreeNode* rightChild) : 
        value(std::make_unique<T>(value)), leftChild(std::make_unique<BinarySearchTreeNode>(leftChild)), rightChild(std::make_unique<BinarySearchTreeNode>(rightChild)) {}

template<typename T>
BinarySearchTreeNode<T>::~BinarySearchTreeNode() = default;

template<typename T>
T BinarySearchTreeNode<T>::getValue() const {
    return *this->valuePtr;
}

template<typename T>
void BinarySearchTreeNode<T>::setValue(const T& value) {
    this->valuePtr = std::make_unique<T>(value);
}

template<typename T>
void BinarySearchTreeNode<T>::setValue(T&& value) {
    this->valuePtr = std::make_unique<T>(value);
}

#endif // BINARY_SEARCH_TREE_NODE_H