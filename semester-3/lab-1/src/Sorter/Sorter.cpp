#include "Sorter.h"

/// @todo Change ::quick_sort() to template template format 
// /**
//  * @brief Sorts the given Sequence with a quick sort algorithm
//  * 
//  * @tparam T template variable
//  * @param seq sequence which will be sorted
//  * @param comp comparison function which returns ​true if the first 
//  * argument is less than (i.e. is ordered before) the second.
//  */
// template<class T>
// void Sorter<T>::quick_sort(Sequence<T>* seq, function<int (T, T)> comp) {
//     if (seq == nullptr || seq->getSize() <= 1) {
//         return;
//     }

//     quick_sort(seq, comp, 0, seq->getSize() - 1);
// }

// /**
//  * @brief Sorts the given Sequence with a quick sort algorithm recursively
//  *
//  * @tparam T template variable
//  * @param seq sequence which will be sorted
//  * @param comp comparison function which returns ​true if the first
//  * argument is less than (i.e. is ordered before) the second.
//  * @param start index to start sorting with (inclusive)
//  * @param end index to end sorting with (inclusive)
//  */
// template<class T>
// void Sorter<T>::quick_sort(Sequence<T>* seq, function<int (T, T)> comp, int start, int end) {
//     if (start < 0 || end < 0 || start >= end)
//         return;

//     int pivot_index = hoare_partition(seq, comp, start, end);
//     quick_sort(seq, comp, start, pivot_index);
//     quick_sort(seq, comp, pivot_index + 1, end);
// }

// /**
//  * @brief Returns the index of the pivot element with the Hoare's partition algorithm
//  * 
//  * @tparam T template variable
//  * @param seq sequence which will be sorted
//  * @param comp comparison function which returns ​true if the first
//  * argument is less than (i.e. is ordered before) the second.
//  * @param start index to start sorting with (inclusive)
//  * @param end index to end sorting with (inclusive)
//  * @return int index of the pivot element
//  */
// template<class T>
// int Sorter<T>::hoare_partition(Sequence<T>* seq, function<int (T, T)> comp, int start, int end) {
//     T pivot = seq->get((start + end) / 2);

//     int left = start;
//     int right = end;

//     while (true) {
//         while (comp(seq->get(left), pivot) == -1) {
//             left++;
//         }

//         while (comp(seq->get(right), pivot) == 1) {
//             right--;
//         }

//         if (left >= right)
//             return right;
        
//         seq->swap(left, right);
//         left++;
//         right--;
//     }
// }

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
    if (seq->getSize() > 1) {
        *seq = *merge_sort(seq, comp, 0, seq->getSize() - 1);
    }
}

/**
 * @brief Sorts the given Sequence with a merge sort algorithm recursively
 * 
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`
 * @tparam V late variable. For example `int`, `double` or `float` etc.
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting  with (inclusive)
 * @return T<V>* pointer to the new sequence with sorted part of `seq`
 */
template<template<class> class T, class V>
T<V>* Sorter<T, V>::merge_sort(T<V>* seq, function<int(V, V)> comp, int start, int end) {
    if (start == end) 
        return (T<V>*) seq->getSubSequence(start, end + 1);
    
    if (start < 0 || end < 0 || start > end)
        return nullptr;
        // ERROR!

    int middle = (start + end) / 2;
    cout << "Middle: " << middle << endl;

    T<V>* leftSequence = merge_sort(seq, comp, start, middle);
    T<V>* rightSequence = merge_sort(seq, comp, middle + 1, end);

    cout << "leftSequence size = " << leftSequence->getSize() << endl;
    for (int i(0); i < leftSequence->getSize(); i++) 
        cout << leftSequence->get(i) << " ";
    
    cout << endl << "rightSequence size = " << rightSequence->getSize() << endl;
    for (int i(0); i < rightSequence->getSize(); i++)
        cout << rightSequence->get(i) << " ";
    cout << endl;

    if (end - start == 1) {
        if (seq->get(start) > seq->get(end)) {
            seq->swap(start, end);
            return (T<V>*) seq->getSubSequence(start, end + 1);
        }
    }

    int left = 0;
    int right = 0;

    T<V>* mergedSequence = new T<V>();

    while (left < leftSequence->getSize() && right < rightSequence->getSize()) {
        if (leftSequence->get(left) < rightSequence->get(right)) {
            mergedSequence->append(leftSequence->get(left));
            left++;
        } else {
            mergedSequence->append(rightSequence->get(right));
            right++;
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