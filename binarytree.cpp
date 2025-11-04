#include "binarytree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(int value) {
    insert(root, value);
}

void BinaryTree::insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->value) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

std::vector<int> BinaryTree::inOrderTraversal() const {
    std::vector<int> result;
    inOrder(root, result);
    return result;
}

void BinaryTree::inOrder(Node* node, std::vector<int>& result) const {
    if (!node) return;
    inOrder(node->left, result);
    result.push_back(node->value);
    inOrder(node->right, result);
}

std::vector<int> BinaryTree::preOrderTraversal() const {
    std::vector<int> result;
    preOrder(root, result);
    return result;
}

void BinaryTree::preOrder(Node* node, std::vector<int>& result) const {
    if (!node) return;
    result.push_back(node->value);
    preOrder(node->left, result);
    preOrder(node->right, result);
}

std::vector<int> BinaryTree::postOrderTraversal() const {
    std::vector<int> result;
    postOrder(root, result);
    return result;
}

void BinaryTree::postOrder(Node* node, std::vector<int>& result) const {
    if (!node) return;
    postOrder(node->left, result);
    postOrder(node->right, result);
    result.push_back(node->value);
}
bool BinaryTree::search(int value) const {
    return search(root, value);
}

bool BinaryTree::search(Node* node, int value) const {
    if (!node) return false;
    if (node->value == value) return true;
    if (value < node->value)
        return search(node->left, value);
    else
        return search(node->right, value);
}



Node* BinaryTree::getRoot() const {
    return root;
}
