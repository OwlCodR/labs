#ifndef SEQUENCE_H
#define SEQUENCE_H

using namespace std;

template<class T>
class Sequence {
public:
    T getFirst();
    T getLast();
    T get(int index);
    int getSize();

    void append(T item);
    void prepend(T item);
    void insertAt(T item, int index);
    Sequence<T>* concat(Sequence<T> *list);
    Sequence<T>* getSubSequence(int startIndex, int endIndex);
};

#endif