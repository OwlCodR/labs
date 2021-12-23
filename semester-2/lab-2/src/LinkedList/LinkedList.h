#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "../Node/Node.h"

using namespace std;

template <class T>
class LinkedList {
public:
    LinkedList(T* items, int count);
    LinkedList();
    LinkedList(const LinkedList<T>& list);

    ~LinkedList();

    Node<T>* getFirstNode() const;
    T getFirst();
    T getLast();
    T get(int index);
    T& operator[](const int index);
    
    int getSize();
    int getSize() const;

    void set(int index, T value);
    void append(T value);
    void prepend(T value);
    void insertAt(int index, T value);
    void swapValues(int index1, int index2);

    LinkedList<T>* concat(LinkedList<T>* list);
    LinkedList<T>* getSubList(int startIndex, int endIndex);

    // Try Catch check
private:
    Node<T>* first;
    Node<T>* last;

    int size;

    void init();
};

#endif