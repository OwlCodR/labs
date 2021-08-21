#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
public:
    Node* right;
    Node* left;
    T value;
    bool leftIsThread, rightIsThread;

    Node(T value, Node* right, Node* left) {
        this->value = value;
        this->right = right;
        this->left = left;
        
        leftIsThread = false;
        rightIsThread = false;
    }

    Node(T value) {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;

        leftIsThread = false;
        rightIsThread = false;
    }

    Node() {
        this->right = nullptr;
        this->left = nullptr;

        leftIsThread = false;
        rightIsThread = false;
    }
};

#endif