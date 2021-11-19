#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
#include <string>
#include "src/UI/UI.h"
#include "src/VectorSequence/VectorSequence.h"
#include "src/Sorter/Sorter.h"
#include "../../semester-2/lab-2/include/DynamicArray.hpp"
#include "../../semester-2/lab-2/include/ArraySequence.hpp"
#include "../../semester-2/lab-2/include/LinkedList.hpp"
#include "../../semester-2/lab-2/include/ListSequence.hpp"

using namespace std;

int comp(int num1, int num2) {
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

template<template<class> class T, class V>
void printSequence(string msg, T<V>& seq) {
    cout << msg << endl;

    for (int i(0); i < seq.getSize(); i++) {
        cout << seq.get(i) << " ";
    }

    cout << endl;
}

template<template<class> class T, class V>
T<V> getSequenceInput() {
    T<V> sequence;
    int size;

    cout << "Size of Sequence: ";
    cin >> size;

    for (int i(0); i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        
        V element;
        cin >> element;

        sequence.append(element);
    }

    cout << "Done! Size of created sequence: " << sequence.getSize() << endl;

    return sequence;
}

template<template<class> class T, class V>
T<V> getSequenceRand() {
    T<V> sequence;
    int size, min, max;
    
    cout << "Size of Sequence: ";
    cin >> size;

    cout << "Min element: ";
    cin >> min;
    
    cout << "Max element: ";
    cin >> max;

    cout << "Appending elements..." << endl;

    srand(time(nullptr));
    for (int i(0); i < size; i++) {
        V random = rand() % (max - min) + min;
        sequence.append(random);
    }

    cout << "Done! Size of created sequence: " << sequence.getSize() << endl;

    return sequence;
}

template<template<class> class T, class V>
T<V> getUserSequence() {
    cout << endl << "Choose input method of sequence:" << endl;

    cout << "1. Random generation" << endl;
    cout << "2. Input manually" << endl;
    cout << "[Warning] Input manually works only with int/float/double because it's using rand()" << endl;

    int answer;
    cin >> answer;

    if (answer == 1) {
        return getSequenceRand<T, V>();
    } else {
        return getSequenceInput<T, V>();
    }
}

template<template<class> class T, class V>
bool isSequenceWillShow(T<V>& seq) {
    cout << endl << "Do you want to see sorted sequence?" << endl;

    if (seq.getSize() > 99)
        cout << "[Warning] It may fill all your terminal with numbers and takes much time if size is too big." << endl;

    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int answer;
    cin >> answer;

    if (answer == 1) {
        return true;
    } else {
        cout << "Ok." << endl;
        return false;
    }
}

template<template<class> class T, class V>
void uiSort(typename Sorter<T, V>::sort_f sort, function<int(V, V)> comp) {
    T<V> sequence = getUserSequence<T, V>();

    bool showSequence = isSequenceWillShow<T, V>(sequence);

    if (showSequence)
        printSequence<T, V>(string("Unsorted sequence: "), sequence);

    cout << "Sorting..." << endl;
    double sort_time = Sorter<T, V>::sort_time(sort, &sequence, comp);
    cout << "Sorted!" << endl;

    if (showSequence) 
        printSequence<T, V>(string("Sorted sequence: "), sequence);
    
    cout << endl << "Sorted! Statistic is here:" << endl;
    cout << "Sequence size: " << sequence.getSize() << endl;
    cout << "Sort time: " << sort_time << "ms" << endl << endl;
}

template<template<class> class T, class V>
void uiChooseSortAlgorithm(function<int(V, V)> comp) {
    cout << endl << "Choose the sort algorithm: " << endl;

    cout << "1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Insertion Sort" << endl;

    int answer;
    cin >> answer;

    if (answer == 1) {
        uiSort<T, V>(Sorter<T, V>::quick_sort, comp);
    } else if (answer == 2) {
        uiSort<T, V>(Sorter<T, V>::merge_sort, comp);
    } else {
        uiSort<T, V>(Sorter<T, V>::insertion_sort, comp);
    }
}

template<class V>
void uiChooseSequenceType(function<int(V, V)> comp) {
    cout << endl << "Choose the type of sequence: " << endl;

    cout << "1. ArraySequence" << endl;
    cout << "2. ListSequence" << endl;

    int answer;
    cin >> answer;

    if (answer == 1) {
        uiChooseSortAlgorithm<ArraySequence, V>(comp);
    } else {
        uiChooseSortAlgorithm<ListSequence, V>(comp);
    }
}

void uiChooseDataType() {
    cout << endl << "Choose data type of sequence: " << endl;

    cout << "1. int" << endl;
    cout << "2. double" << endl;
    cout << "3. float" << endl;

    int answer;
    cin >> answer;

    if (answer == 1) {
        uiChooseSequenceType<int>(comp);
    } else if (answer == 2) {
        uiChooseSequenceType<double>(comp);
    } else {
        uiChooseSequenceType<float>(comp);
    }
}

void uiTests() {
    //
}

void uiExit() {
    cout << "Exit." << endl;
    exit(0);
}

int main()
{
    map<string, function<void()>> functions;
    functions["Sort sequence"] = uiChooseDataType;
    functions["Tests"] = uiTests;
    functions["Exit"] = uiExit;
    
    UI ui(functions);
    ui.setTitle("MEGA PROGRAM 9000");
    ui.start();

    return 0;
}
