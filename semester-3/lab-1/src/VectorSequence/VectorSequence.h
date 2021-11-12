#ifndef VECTOR_SEQUENCE_H
#define VECTOR_SEQUENCE_H

#include "../../../../semester-2/lab-2/src/Sequence/Sequence.h"
#include <vector>
/**
 * @brief Seuqnece child based on the std::vector<T>. 
 * Attention! concat() and getSubSequence() returns `nullptr`
 * 
 * @tparam T template class
 */
template<class T>
class VectorSequence : public Sequence<T> {
public:
    T getFirst() {
        return vec[0];
    }

    T getLast() {
        return vec[vec.size() - 1];
    }

    T get(int index) {
        return vec[index];
    }

    T get(int index) const {
        return vec[index];
    }

    int getSize() {
        return vec.size();
    }

    int getSize() const {
        return vec.size();
    }
    
    void append(T item) {
        vec.push_back(item);
    }

    void prepend(T item) {
        vec.insert(vec.begin(), item);
    }

    void insertAt(int index, T item) {
        vec.insert(vec.begin() + index, item);
    }

    void swap(int index1, int index2) {
        iter_swap(vec.begin() + index1, vec.begin() + index2);
    }

    Sequence<T>* concat(const Sequence<T>* list) {
        return nullptr;
    }

    Sequence<T>* getSubSequence(int startIndex, int endIndex) {
        return nullptr;
    }
private:
    vector<T> vec;
};

#endif