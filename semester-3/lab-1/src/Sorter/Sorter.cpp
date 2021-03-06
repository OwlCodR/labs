#include "Sorter.h"

/**
 * @brief Sorts the given Sequence with a quick sort algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
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
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting with (inclusive)
 */
template<template<class> class T, class V>
void Sorter<T, V>::quick_sort_recursive(T<V>* seq, function<int(V, V)>* comp, int start, int end) {
    if (start < 0 || end < 0 || start >= end)
        return;

    int pivot_index = hoare_partition(seq, comp, start, end);
    quick_sort_recursive(seq, comp, start, pivot_index);
    quick_sort_recursive(seq, comp, pivot_index + 1, end);
}

/**
 * @brief Returns the index of the pivot element with the Hoare's partition algorithm
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting with (inclusive)
 * @return int index of the pivot element
 */
template<template<class> class T, class V>
int Sorter<T, V>::hoare_partition(T<V>* seq, function<int(V, V)>* comp, int start, int end) {
    V pivot = seq->get((start + end) / 2);

    int left = start;
    int right = end;

    while (true) {
        while ((*comp)(seq->get(left), pivot) == -1) {
            left++;
        }

        while ((*comp)(seq->get(right), pivot) == 1) {
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
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 */
template<template<class> class T, class V>
void Sorter<T, V>::merge_sort(T<V>* seq, function<int(V, V)> comp) {
    if (seq == nullptr || seq->getSize() <= 1)
        return;

    *seq = *merge_sort_recursive(seq, &comp, 0, seq->getSize() - 1);
}

/**
 * @brief Sorts the given Sequence with a merge sort algorithm recursively
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting  with (inclusive)
 * @return T<V>* pointer to the new sequence with sorted part of `seq`
 */
template<template<class> class T, class V>
T<V>* Sorter<T, V>::merge_sort_recursive(T<V>* seq, function<int(V, V)>* comp, int start, int end) {
    if (start == end) {
        T<V>* sequence = new T<V>();
        sequence->append(seq->get(start));
        return sequence;
    }

    if (start < 0 || end < 0 || start > end)
        return nullptr;
    // ERROR!

    int middle = (start + end) / 2;

    T<V>* leftSequence = merge_sort_recursive(seq, comp, start, middle);
    T<V>* rightSequence = merge_sort_recursive(seq, comp, middle + 1, end);

    if (end - start == 1) {
        if ((*comp)(seq->get(start), seq->get(end)) == 1) {
            seq->swap(start, end);

            T<V>* sequence = new T<V>();
            sequence->append(seq->get(start));
            return sequence;
        }
    }

    int left = 0;
    int right = 0;

    T<V>* mergedSequence = new T<V>();

    while (left < leftSequence->getSize() && right < rightSequence->getSize()) {
        if ((*comp)(leftSequence->get(left), rightSequence->get(right)) == 1) {
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
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 */
template<template<class> class T, class V>
void Sorter<T, V>::insertion_sort(T<V>* seq, function<int(V, V)> comp) {
    if (seq == nullptr || seq->getSize() <= 1)
        return;

    for (int i(1); i < seq->getSize(); i++) {
        V pivot = seq->get(i);
        int k = i - 1;

        while (k >= 0 && comp(seq->get(k), pivot) == 1) {
            seq->set(k + 1, seq->get(k));
            k--;
        }

        seq->set(k + 1, pivot);
    }
}

/**
 * @brief Measures the time it took for a function to sort a sequence.
 * [Copy constructor for sequence is REQUIRED]
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param sort function which will be used to sort sequence
 * @param seq sequence which will NOT be sorted. It will make a copy of sequence
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 *
 * @return double sorting time in ms
 */
template<template<class> class T, class V>
double Sorter<T, V>::sort_time(sort_f sort, T<V> seq, function<int(V, V)> comp) {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    auto start = high_resolution_clock::now();
    sort(&seq, comp);
    auto end = high_resolution_clock::now();

    duration<double, std::milli> time = end - start;

    return time.count();
}

/**
 * @brief Measures the time it took for a function to sort a sequence.
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param sort function which will be used to sort sequence
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 *
 * @return double sorting time in ms
 */
template<template<class> class T, class V>
double Sorter<T, V>::sort_time(sort_f sort, T<V>* seq, function<int(V, V)> comp) {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    auto start = high_resolution_clock::now();
    sort(seq, comp);
    auto end = high_resolution_clock::now();

    duration<double, std::milli> time = end - start;

    return time.count();
}

/**
 * @brief Measures the time it took for functions to sort a sequence and calculates the difference.
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param sort1 first function which will be used to sort sequence (Minuend)
 * @param sort2 second function which will be used to sort sequence (Subtrahend)
 * @param seq sequence which will NOT be changed. It will sort a copy of that sequence
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 * @return double sort1_time - sort2_time
 */
template<template<class> class T, class V>
double Sorter<T, V>::sort_time_difference(sort_f sort1, sort_f sort2, T<V> seq, function<int(V, V)> comp) {

    double sort_time1 = sort_time(sort1, seq, comp);
    double sort_time2 = sort_time(sort2, seq, comp);

    return sort_time1 - sort_time2;
}

/**
 * @brief Measures the time it took for functions to sort a sequence and calculates the difference.
 *
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 * @param sort1 first function which will be used to sort sequence (Minuend)
 * @param sort2 second function which will be used to sort sequence (Subtrahend)
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns 1 if the first
 * argument is greater than the second. Returns 0 if they are equal. 
 * Returns -1 if first is less than second
 * @return double sort1_time - sort2_time
 */
template<template<class> class T, class V>
double Sorter<T, V>::sort_time_difference(sort_f sort1, sort_f sort2, T<V>* seq, function<int(V, V)> comp) {

    double sort_time1 = sort_time(sort1, *seq, comp);   // unsorted copy of seq
    double sort_time2 = sort_time(sort2, seq, comp);    // also sort

    return sort_time1 - sort_time2;
}
