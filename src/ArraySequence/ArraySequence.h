#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"

template<class T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence();
    ArraySequence(T* items, int count);
    ~ArraySequence();

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

    T& operator[](int index);

    void print(bool debug);
    string to_string();
private:
    DynamicArray<T>* dynamicArray;
};

#endif