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

    Node(T value) {
        // cout << "Node constructor" << endl;
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;

        leftIsThread = false;
        rightIsThread = false;
    }

    Node() {
        // cout << "Node empty constructor" << endl;

        this->right = nullptr;
        this->left = nullptr;

        leftIsThread = false;
        rightIsThread = false;
    }
};

#endif