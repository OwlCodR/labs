#ifndef SORTER_H
#define SORTER_H

#include <functional>
#include "../../../../semester-2/lab-2/src/Sequence/Sequence.h"
#include "../../../../semester-2/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../../semester-2/lab-2/src/ListSequence/ListSequence.h"

/// @todo remove
using namespace std;

template<template<class> class T, class V>
class Sorter {
public:
    static void quick_sort(T<V>* seq, function<int (V, V)> comp);
    static void merge_sort(T<V>* seq, function<int(V, V)> comp);
    static void insertion_sort(T<V>* seq, function<int (V, V)> comp);
private:
    static T<V>* merge_sort(T<V>* seq, function<int(V, V)> comp, int start, int end);
    static void quick_sort(T<V>* seq, function<int (V, V)> comp, int start, int end);
    static int hoare_partition(T<V>* seq, function<int (V, V)> comp, int start, int end);
};

/// @todo UPDATE COMP DOC!!!

#endif