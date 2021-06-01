#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "LinkedList.h"
#include "Sequence.h"

template<class T>
class ListSequence : public Sequence<T> {
public:
    ListSequence();
    ListSequence(T* items, int count);
    ListSequence(const LinkedList<T>* list);

    ~ListSequence();

    T getFirst();
    T getLast();
    T get(int index);
    T get(int index) const;
    int getSize();
    int getSize() const;

    void append(T item);
    void prepend(T item);
    void insertAt(int index, T item);
    Sequence<T>* concat(const Sequence<T> *list);
    Sequence<T>* getSubSequence(int startIndex, int endIndex);

    void print(bool debug);
    string to_string();
private:
    LinkedList<T>* linkedList;
};

#endif