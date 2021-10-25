#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "../LinkedList/LinkedList.h"
#include "../Sequence/Sequence.h"
#include "../Node/Node.h"

template<class T>
class ListSequence : public Sequence<T> {
public:
    ListSequence();
    ListSequence(T* items, int count);
    ListSequence(const LinkedList<T>* list);

    ~ListSequence();

    Node<T>* getFirstNode();
    T getFirst();
    T getLast();
    T get(int index);
    T get(int index) const;
    int getSize();
    int getSize() const;
    LinkedList<T> getLinkedList() const;

    void append(T item);
    void prepend(T item);
    void insertAt(int index, T item);
    void swap(int index1, int index2);
    Sequence<T>* concat(const Sequence<T> *list);
    Sequence<T>* getSubSequence(int startIndex, int endIndex);
private:
    LinkedList<T>* linkedList;
};

#endif