#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

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

template <class T>
class LinkedList {
public:
    LinkedList(T* items, int count);
    LinkedList();
    LinkedList(const LinkedList<T>& list);

    T getFirst();
    T getLast();
    T get(int index);
    T& operator[](const int index);
    
    int getSize();
    void append(T value);
    void prepend(T value);
    void insertAt(int index, T value);

    LinkedList<T>* concat(LinkedList<T>* list);
    LinkedList<T>* getSubList(int startIndex, int endIndex);

    void print(bool debug);
    string to_string();

    // Try Catch check
private:
    Node<T>* first;
    Node<T>* last;

    int size;

    void init();
};

#endif