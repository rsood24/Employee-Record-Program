#ifndef BSTREE_
#define BSTREE_
#include <iostream>
using namespace std;
#include "Node.h"

// Binary Search Tree class
class BSTree {
private:
    Node* root = nullptr;
    void addNode(Node* leaf, Node* a_set);
    Node* deleteNode(Node* node, double key);
    void freeNode(Node* leaf);
public:
    BSTree();
    ~BSTree();
    Node* Root() { return root; }
    void setRoot(Node * _root) {root = _root;}
    void addNode(Node* a_set);
    Node* findNode(double key, Node* parent);
    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);
    
    
    void deleteNode(double key);
    
    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(double key, Node* parent);
    Node* predecessor(double key, Node* parent);
    
};
#endif  //BST