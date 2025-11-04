#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {

public:
    BinaryTree();
    void insert(int value);
    Node* getRoot() const;

private:
    Node* root;
    void insert(Node*& node, int value);

public:
    std::vector<int> inOrderTraversal() const;
    std::vector<int> preOrderTraversal() const;
    std::vector<int> postOrderTraversal() const;
    bool search(int value) const;
    void remove(int value);
    ~BinaryTree();  // Destructor
    void clear();   // Método público opcional para limpiar el árbol




private:
    void inOrder(Node* node, std::vector<int>& result) const;
    void preOrder(Node* node, std::vector<int>& result) const;
    void postOrder(Node* node, std::vector<int>& result) const;
    bool search(Node* node, int value) const;
    void destroy(Node* node);  // Función recursiva para liberar nodos
    void remove(Node*& node, int value);
    Node* findMin(Node* node);









};

#endif // BINARYTREE_H
