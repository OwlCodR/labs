#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
public:
    Node* next;
    T value;

    Node(T value, Node* next) {
        this->value = value;
        this->next = next;
    }

    Node(T value) {
        this->value = value;
        this->next = nullptr;
    }

    Node() {
        this->next = nullptr;
    }
};

#endif