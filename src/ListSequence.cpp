#include "ListSequence.h"

template<class T>
ListSequence<T>::ListSequence() {}

template<class T>
ListSequence<T>::ListSequence(T* items, int count) {
    linkedList = new LinkedList<T>(items, count);
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
void ListSequence<T>::insertAt(T item, int index) {
    linkedList->insertAt(index, item);
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
    ListSequence<T>* sequence = new ListSequence<T>();
    for (int i(startIndex); i < endIndex; i++) {
        sequence->append(linkedList->get(i));
    }
    return sequence;
}

template<class T>
void ListSequence<T>::print(bool debug) {
    linkedList->print(debug);
}

template<class T>
string ListSequence<T>::to_string() {
    return linkedList->to_string();
}