#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "../Node/Node.h"
#include <string>
#include <stack>

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(T value);
    ~BinarySearchTree();

    Node<T>* getRoot();
    int getDepthOf(Node<T>* node);
    int getDepthOf(T value);
    int getHeight();
    void add(Node<T>* node);
    void remove(Node<T>* node);
    void removeRecursive(Node<T>* node);
    void sew();
    
    void fromString(string input, string bypass);
    string toString(string bypass);
    
    BinarySearchTree getSubTree(Node<T>* subRoot);
    Node<T>* findSubTreeRoot(BinarySearchTree& subTree);
    Node<T>* findSubTreeRoot(Node<T>* subRoot);
    Node<T>* findNode(string path); // LLRLRLRL or /LRLRRL

    BinarySearchTree merge(BinarySearchTree& tree1, BinarySearchTree& tree2);
private:
    Node<T>* root;
};

#endif