#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    root = new Node<T>(value);
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    remove(root);
}


template<class T>
Node<T>* BinarySearchTree<T>::getRoot() {
    return root;
}

template<class T>
void BinarySearchTree<T>::sew() {
    while 
}

template<class T>
int BinarySearchTree<T>::getDepthOf(Node<T>* depth_node) {
    Node<T> node = root;
    int counter = 0;

    while (node != nullptr) {
        counter++;

        if (depth_node->value < node->value) {
            node = node->left; // nullptr
        } else if (depth_node->value > node->value) {
            node = node->right;
        } else {
            return counter - 1;
        }
    }

    return -1;
}

template<class T>
int BinarySearchTree<T>::getDepthOf(T value) {
    Node<T> node(value);
    return getDepthOf(node);
}

template<class T>
int BinarySearchTree<T>::getHeight() {
    Node<T> node = root;
    stack<Node<T>*> rightNodes;
    int max_depth = 0;
    int depth = 0;
    int counter = 0;

    while (node != nullptr || !rightNodes.empty()) {
        if (node != nullptr) {
            if (node->right != nullptr)
                rightNodes.push(node->right);
            node = node->left;
            depth++;
        } else {
            node = rightNodes.top();

            if (depth > max_depth) {
                max_depth = depth;
            }

            rightNodes.pop();
            depth -= counter;
            counter = 0;
        }
    }
    return max_depth;
}

template<class T>
void BinarySearchTree<T>::add(Node<T>* node) {
    
}

template<class T>
void BinarySearchTree<T>::remove(Node<T>* node) {
    
}

template<class T>
void BinarySearchTree<T>::removeRecursive(Node<T>* node) {
    
}

template<class T>
void BinarySearchTree<T>::fromString(string input, string bypass) {
    
}

template<class T>
string BinarySearchTree<T>::toString(string bypass) {
    
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::getSubTree(Node<T>* subRoot) {
    
}

template<class T>
Node<T>* BinarySearchTree<T>::findSubTreeRoot(BinarySearchTree& subTree) {
    
}

template<class T>
Node<T>* BinarySearchTree<T>::findSubTreeRoot(Node<T>* subRoot) {
    
}

template<class T>
Node<T>* BinarySearchTree<T>::findNode(string path) {
    
} // LLRLRLRL or /LRLRRL

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::merge(BinarySearchTree& tree1, BinarySearchTree& tree2) {
    
}
