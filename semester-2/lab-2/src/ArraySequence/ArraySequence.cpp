#include "ArraySequence.h"

template<class T>
ArraySequence<T>::ArraySequence(T* items, int count) {
    dynamicArray = new DynamicArray<T>(items, count);
}

template<class T>
ArraySequence<T>::ArraySequence() {
    dynamicArray = new DynamicArray<T>();
}

template<class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>& seq) {
    dynamicArray = new DynamicArray<T>(seq.getDynamicArray());
}

template<class T>
ArraySequence<T>::~ArraySequence() {
    delete dynamicArray;
}

template<class T>
T ArraySequence<T>::getFirst() {
    return dynamicArray->get(0);
}

template<class T>
T ArraySequence<T>::getLast() {
    return dynamicArray->get(getSize() - 1);
}

template<class T>
T ArraySequence<T>::get(int index) {
    return dynamicArray->get(index);
}

template<class T>
T ArraySequence<T>::get(int index) const {
    return dynamicArray->get(index);
}

template<class T>
void ArraySequence<T>::set(int index, T item) {
    dynamicArray->set(index, item);
}

template<class T>
DynamicArray<T> ArraySequence<T>::getDynamicArray() const {
    return *dynamicArray;
}

template<class T>
int ArraySequence<T>::getSize() {
    return dynamicArray->getSize();
}

template<class T>
int ArraySequence<T>::getSize() const {
    return dynamicArray->getSize();
}

template<class T>
void ArraySequence<T>::append(T item) {
    if (dynamicArray->getCapacity() <= getSize())
        dynamicArray->resize(getSize() + 1);

    dynamicArray->set(getSize(), item);
}

template<class T>
void ArraySequence<T>::prepend(T item) {
    if (dynamicArray->getCapacity() < getSize() + 1)
        dynamicArray->resize(getSize() + 1);

    for (int i(getSize() - 1); i > 0; i--)
        dynamicArray->set(i, dynamicArray->get(i - 1));

    dynamicArray->set(0, item);
}

template<class T>
void ArraySequence<T>::insertAt(int index, T item) {
    try
    {
        if (index < 0 || index > getSize())
            throw "IndexOutOfRange";
        else {
            if (index == 0) {
                prepend(item);
                return;
            } else if (index == getSize()) {
                append(item);
                return;
            }

            if (dynamicArray->getCapacity() < getSize() + 1)
                dynamicArray->resize(getSize() + 1);

            for (int i(getSize() - 1); i >= 0; i--) {
                if (i == index) {
                    dynamicArray->set(i, item);
                    return;
                }
                dynamicArray->set(i, dynamicArray->get(i - 1));
            }
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T>
void ArraySequence<T>::swap(int index1, int index2) {
    T buff = dynamicArray->get(index1);
    dynamicArray->set(index1, dynamicArray->get(index2));
    dynamicArray->set(index2, buff);
}

template<class T>
Sequence<T>* ArraySequence<T>::concat(const Sequence<T> *list) {
    ArraySequence<T>* sequence = new ArraySequence<T>();

    for (int i(0); i < dynamicArray->getSize(); i++) {
        sequence->append(dynamicArray->get(i));
    }

    for (int i(0); i < list->getSize(); i++) {
        sequence->append(list->get(i));
    }
    return sequence;
}

template<class T>
Sequence<T>* ArraySequence<T>::getSubSequence(int startIndex, int endIndex) {
    try
    {
        if (startIndex < 0 || startIndex > getSize() || endIndex < 0 || endIndex > getSize() || startIndex > endIndex)
            throw "IndexOutOfRange";
        else {
            ArraySequence<T>* sequence = new ArraySequence<T>();
            for (int i(startIndex); i < endIndex; i++) {
                sequence->append(dynamicArray->get(i));
            }
            return sequence;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T> 
T& ArraySequence<T>::operator[](int index) {
    return (*dynamicArray)[index];
}

template<class T> 
T ArraySequence<T>::operator[](int index) const {
    return (*dynamicArray)[index];
}