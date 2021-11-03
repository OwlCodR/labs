#include "Sorter.h"

/**
 * @brief Sorts the given Sequence with a quick sort algorithm
 * 
 * @tparam T template variable
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first 
 * argument is less than (i.e. is ordered before) the second.
 */
template<class T>
void Sorter<T>::quick_sort(Sequence<T>* seq, function<int (T, T)> comp) {
    if (seq == nullptr || seq->getSize() <= 1) {
        return;
    }

    quick_sort(seq, comp, 0, seq->getSize() - 1);
}

/**
 * @brief Sorts the given Sequence with a quick sort algorithm recursively
 *
 * @tparam T template variable
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start sorting with (inclusive)
 * @param end index to end sorting with (not inclusive)
 */
template<class T>
void Sorter<T>::quick_sort(Sequence<T>* seq, function<int (T, T)> comp, int start, int end) {
    if (start < 0 || end < 0 || start >= end)
        return;

    int pivot_index = hoare_partition(seq, comp, start, end);
    quick_sort(seq, comp, start, pivot_index);
    quick_sort(seq, comp, pivot_index + 1, end);
}

/**
 * @brief Returns the index of the pivot element with the Hoare's partition algorithm
 * 
 * @tparam T template variable
 * @param seq sequence which will be sorted
 * @param comp comparison function which returns ​true if the first
 * argument is less than (i.e. is ordered before) the second.
 * @param start index to start with (inclusive)
 * @param end index to end with (not inclusive)
 * @return int index of the pivot element
 */
template<class T>
int Sorter<T>::hoare_partition(Sequence<T>* seq, function<int (T, T)> comp, int start, int end) {
    T pivot = seq->get((start + end) / 2);

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

template<class T>
void merge_sort(Sequence<T>* seq, function<int (T, T)> comp) {
    if (seq->getSize() > 1) {
        
    }
}