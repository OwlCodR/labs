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
    BinarySearchTree(Node<T>* new_root);
    ~BinarySearchTree();

    Node<T>* getRoot();
    Node<T>* findNode(T value); //  Поиск
    int getDepthOf(Node<T>* node);
    int getDepthOf(T value);
    int getHeight();
    void add(Node<T>* node);
    void add(T value);
    void remove(Node<T>* node);
    void sew(); // Прошивка
    
    BinarySearchTree<T> fromString(string input, string bypass);
    string toString(string bypass);

    BinarySearchTree<T> findSubTree(BinarySearchTree& subTree);
    BinarySearchTree<T> findSubTree(Node<T>* subRoot);
    BinarySearchTree<T> findSubTree(T value);
    Node<T>* findNodeByPath(Node<T>* node, string path);
    Node<T>* findNodeByPath(string path);

    BinarySearchTree<T> merge(BinarySearchTree<T>& tree1, BinarySearchTree<T>& tree2);
private:
    Node<T>* root;

    string toString(char* brackets, char* bypass);
    BinarySearchTree<T> fromString(string input, char* brackets, char* bypass);
};

#endif