#ifndef SORTER_H
#define SORTER_H

#include <functional>
#include <ctime>
#include <chrono>

#include "../../../../semester-2/lab-2/src/Sequence/Sequence.h"
#include "../../../../semester-2/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../../semester-2/lab-2/src/ListSequence/ListSequence.h"

/// @todo remove
using namespace std;

/// @todo UPDATE COMP DOC!!!

template<template<class> class T, class V>
class Sorter {
public:
    static void quick_sort(T<V>* seq, function<int (V, V)> comp);
    static void merge_sort(T<V>* seq, function<int (V, V)> comp);
    static void insertion_sort(T<V>* seq, function<int (V, V)> comp);
    static double sort_time(function<void(T<V>*, function<int(V, V)>)> sort, T<V>* seq, function<int(V, V)> comp);
private:
    static T<V>* merge_sort_recursive(T<V>* seq, function<int (V, V)> comp, int start, int end);
    static void quick_sort_recursive(T<V>* seq, function<int (V, V)>* comp, int start, int end);
    static int hoare_partition(T<V>* seq, function<int (V, V)> comp, int start, int end);
};

/**
 * @brief Sorts the given Sequence with a quick sort algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 */
template<template<class> class T, class V>
void Sorter<T, V>::quick_sort(T<V>* seq, function<int(V, V)> comp) {
    if (seq == nullptr || seq->getSize() <= 1) {
        return;
    }

    quick_sort_recursive(seq, &comp, 0, seq->getSize() - 1);
}

/**
 * @brief Sorts the given Sequence with a quick sort algorithm recursively
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting with (inclusive)
 */
template<template<class> class T, class V>
void Sorter<T, V>::quick_sort_recursive(T<V>* seq, function<int(V, V)>* comp, int start, int end) {
    if (start < 0 || end < 0 || start >= end)
        return;

    int pivot_index = hoare_partition(seq, *comp, start, end);
    quick_sort_recursive(seq, comp, start, pivot_index - 1);
    quick_sort_recursive(seq, comp, pivot_index + 1, end);
}

/**
 * @brief Returns the index of the pivot element with the Hoare's partition algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting with (inclusive)
 * @return int index of the pivot element
 */
template<template<class> class T, class V>
int Sorter<T, V>::hoare_partition(T<V>* seq, function<int(V, V)> comp, int start, int end) {
    V pivot = seq->get((start + end) / 2);

    int left = start;
    int right = end;

    while (true) {
        while (comp(seq->get(left), pivot) == -1) {
            left++;
        }

        while (comp(seq->get(right), pivot) == 1) {
            right--;
        }

        if (left >= right)
            return right;

        seq->swap(left, right);
        left++;
        right--;
    }
}

/**
 * @brief Sorts the given Sequence with a merge sort algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 */
template<template<class> class T, class V>
void Sorter<T, V>::merge_sort(T<V>* seq, function<int(V, V)> comp) {
    if (seq == nullptr || seq->getSize() <= 1)
        return;

    *seq = *merge_sort_recursive(seq, comp, 0, seq->getSize() - 1);
}

/**
 * @brief Sorts the given Sequence with a merge sort algorithm recursively
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting  with (inclusive)
 * @return T<V>* pointer to the new sequence with sorted part of `seq`
 */
template<template<class> class T, class V>
T<V>* Sorter<T, V>::merge_sort_recursive(T<V>* seq, function<int(V, V)> comp, int start, int end) {
    if (start == end)
        return (T<V>*) seq->getSubSequence(start, end + 1);

    if (start < 0 || end < 0 || start > end)
        return nullptr;
    // ERROR!

    int middle = (start + end) / 2;

    T<V>* leftSequence = merge_sort_recursive(seq, comp, start, middle);
    T<V>* rightSequence = merge_sort_recursive(seq, comp, middle + 1, end);

    if (end - start == 1) {
        if (comp(seq->get(start), seq->get(end)) == 1) {
            seq->swap(start, end);
            return (T<V>*) seq->getSubSequence(start, end + 1);
        }
    }

    int left = 0;
    int right = 0;

    T<V>* mergedSequence = new T<V>();

    while (left < leftSequence->getSize() && right < rightSequence->getSize()) {
        if (comp(leftSequence->get(left), rightSequence->get(right)) == 1) {
            mergedSequence->append(rightSequence->get(right));
            right++;
        } else {
            mergedSequence->append(leftSequence->get(left));
            left++;
        }
    }

    if (left > leftSequence->getSize() - 1) {
        for (int i(right); i < rightSequence->getSize(); i++)
            mergedSequence->append(rightSequence->get(i));

    } else if (right > rightSequence->getSize() - 1) {
        for (int i(left); i < leftSequence->getSize(); i++)
            mergedSequence->append(leftSequence->get(i));
    }

    return mergedSequence;
}

/**
 * @brief Sorts the given Sequence with a simple insertion sort algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 */
template<template<class> class T, class V>
void Sorter<T, V>::insertion_sort(T<V>* seq, function<int(V, V)> comp) {
    if (seq == nullptr || seq->getSize() <= 1)
        return;

    for (int i(1); i < seq->getSize(); i++) {
        V pivot = seq->get(i);
        int pivot_index = i;

        for (int k(i - 1); k >= 0; k--) {
            if (comp(seq->get(k), pivot) == 1) {
                seq->swap(k, pivot_index);
                pivot_index = k;
            }
        }
    }
}

/**
 * @brief Measures the time it took for a function to sort a sequence. Also sorts function.
 * 
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param sort function which will be used to sort sequence
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * 
 * @return double sorting time in ms
 */
template<template<class> class T, class V>
double Sorter<T, V>::sort_time(function<void(T<V>*, function<int(V, V)>)> sort, T<V>* seq, function<int(V, V)> comp) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    
    auto start = high_resolution_clock::now();
    sort(seq, comp);
    auto end = high_resolution_clock::now();

    duration<double, std::milli> time = end - start;

    return time.count();
}

#endif