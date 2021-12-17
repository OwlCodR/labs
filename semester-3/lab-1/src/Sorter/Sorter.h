#ifndef SORTER_H
#define SORTER_H

#include <functional>
#include <ctime>
#include <chrono>

#include "../../../../semester-2/lab-2/src/Sequence/Sequence.h"
#include "../../../../semester-2/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../../semester-2/lab-2/src/ListSequence/ListSequence.h"

/**
 * @brief Class with several sorting algorithms and tools to measure and compare sorting time.
 * 
 * @tparam T specific child class of Sequence. For example `ArraySequence` or `ListSequence`.
 * @tparam V template variable. For example `int`, `double` or `float` etc.
 */
template<template<class> class T, class V>
class Sorter {
public:
    typedef function<void(T<V>*, function<int(V, V)>)> sort_f;

    static void quick_sort(T<V>* seq, function<int (V, V)> comp);
    static void merge_sort(T<V>* seq, function<int (V, V)> comp);
    static void insertion_sort(T<V>* seq, function<int (V, V)> comp);
    
    static double sort_time(sort_f sort, T<V> seq, function<int(V, V)> comp);
    static double sort_time(sort_f sort, T<V>* seq, function<int(V, V)> comp);
    
    static double sort_time_difference(sort_f sort1, sort_f sort2, T<V> seq, function<int (V, V)> comp);
    static double sort_time_difference(sort_f sort1, sort_f sort2, T<V>* seq, function<int(V, V)> comp);
private:
    static T<V>* merge_sort_recursive(T<V>* seq, function<int (V, V)>* comp, int start, int end);
    static void quick_sort_recursive(T<V>* seq, function<int (V, V)>* comp, int start, int end);
    static int hoare_partition(T<V>* seq, function<int (V, V)>* comp, int start, int end);
};

// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
#include "Sorter.cpp"

#endif
