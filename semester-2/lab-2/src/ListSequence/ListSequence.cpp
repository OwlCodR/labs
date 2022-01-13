#include "ListSequence.h"

template<class T>
ListSequence<T>::ListSequence(T* items, int count) {
    linkedList = new LinkedList<T>(items, count);
}


template<class T>
ListSequence<T>::ListSequence(const ListSequence<T>& list) {
    linkedList = new LinkedList<T>(list.getLinkedList());
}


template<class T>
ListSequence<T>::ListSequence() {
    linkedList = new LinkedList<T>();
}

template<class T>
ListSequence<T>::~ListSequence() {
    delete linkedList;
}

template<class T>
T ListSequence<T>::getFirst() {
    return linkedList->getFirst();
}

template<class T>
T ListSequence<T>::getLast() {
    return linkedList->getLast();
}

template<class T>
T ListSequence<T>::get(int index) {
    return linkedList->get(index);
}

template<class T>
T ListSequence<T>::get(int index) const {
    return linkedList->get(index);
}

template<class T>
void ListSequence<T>::set(int index, T item) {
    linkedList->set(index, item);
}

template<class T>
LinkedList<T> ListSequence<T>::getLinkedList() const {
    return *linkedList;
}

template<class T>
int ListSequence<T>::getSize() {
    return linkedList->getSize();
}

template<class T>
int ListSequence<T>::getSize() const {
    return linkedList->getSize();
}


template<class T>
void ListSequence<T>::append(T item) {
    linkedList->append(item);
}

template<class T>
void ListSequence<T>::prepend(T item) {
    linkedList->prepend(item);
}

template<class T>
void ListSequence<T>::insertAt(int index, T item) {
    linkedList->insertAt(index, item);
}

template<class T>
void ListSequence<T>::swap(int index1, int index2) {
    linkedList->swapValues(index1, index2);
}

template<class T>
Sequence<T>* ListSequence<T>::concat(const Sequence<T> *list) {
    ListSequence<T>* sequence = new ListSequence<T>();

    for (int i(0); i < linkedList->getSize(); i++) {
        sequence->append(linkedList->get(i));
    }

    for (int i(0); i < list->getSize(); i++) {
        sequence->append(list->get(i));
    }
    return sequence;
}

template<class T>
Sequence<T>* ListSequence<T>::getSubSequence(int startIndex, int endIndex) {
    LinkedList<T>* subList = linkedList->getSubList(startIndex, endIndex);
    ListSequence<T>* sequence = new ListSequence<T>();

    for (int i(0); i < subList->getSize(); i++) {
        sequence->append(subList->get(i));
    }

    return sequence;
}