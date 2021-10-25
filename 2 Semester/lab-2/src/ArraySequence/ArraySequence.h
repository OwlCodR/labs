#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "../DynamicArray/DynamicArray.h"
#include "../Sequence/Sequence.h"

template<class T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence();
    ArraySequence(T* items, int count);

    T getFirst();
    T getLast();
    T get(int index);
    T get(int index) const;
    int getSize();
    int getSize() const;
    DynamicArray<T> getDynamicArray() const;

    void append(T item);
    void prepend(T item);
    void insertAt(int index, T item);
    void swap(int index1, int index2);
    Sequence<T>* concat(const Sequence<T> *list);
    Sequence<T>* getSubSequence(int startIndex, int endIndex);

    T& operator[](int index);
    T operator[](int index) const;
private:
    DynamicArray<T>* dynamicArray;
};

#endif