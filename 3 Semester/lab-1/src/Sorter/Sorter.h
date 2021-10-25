#ifndef SORTER_H
#define SORTER_H

#include <functional>
#include "../../../../2 Semester/lab-2/src/Sequence/Sequence.h"

using namespace std;

template<class T>
class Sorter {
public:
    static void quick_sort(Sequence<T>* seq, function<int (T, T)> comp);
    static void merge_sort(Sequence<T>* seq, function<int (T, T)> comp);
    static void insertion_sort(Sequence<T>* seq, function<int (T, T)> comp);
private:
    static void quick_sort(Sequence<T>* seq, function<int (T, T)> comp, int start, int end);
    static int hoare_partition(Sequence<T>* seq, function<int (T, T)> comp, int start, int end);
};

#endif