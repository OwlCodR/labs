#ifndef SEQUENCE_H
#define SEQUENCE_H

using namespace std;

template<class T>
class Sequence {
public:
    virtual T getFirst() = 0;
    virtual T getLast() = 0;
    virtual T get(int index) = 0;
    virtual T get(int index) const = 0;
    virtual int getSize() = 0;
    virtual int getSize() const = 0;

    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(T item, int index) = 0;
    virtual Sequence<T>* concat(const Sequence<T> *list) = 0;
    virtual Sequence<T>* getSubSequence(int startIndex, int endIndex) = 0;

    virtual void print(bool debug) = 0;
    virtual string to_string() = 0;
};

#endif