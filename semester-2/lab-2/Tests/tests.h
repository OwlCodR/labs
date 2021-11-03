#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include "src/Node/Node.h"
#include "src/Matrix/Matrix.h"
#include "src/DynamicArray/DynamicArray.h"
#include "src/LinkedList/LinkedList.h"
#include "src/ArraySequence/ArraySequence.h"
#include "src/ListSequence/ListSequence.h"

using namespace std;

class Tests {
public:
    template<class T>
    void print(const DynamicArray<T>& array, bool isDebug);

    template<class T>
    void print(const LinkedList<T>& array, bool isDebug);

    template<class T>
    void print(const ArraySequence<T>& sequence, bool isDebug);

    template<class T>
    void print(const ListSequence<T>& sequence, bool isDebug);

    template<class T>
    void print(const Matrix<T>& matrix, bool isDebug);

    template<class T>
    string to_string(const DynamicArray<T>& array, bool isDebug);

    template<class T>
    string to_string(const LinkedList<T>& array, bool isDebug);

    template<class T>
    string to_string(const ArraySequence<T>& sequence, bool isDebug);

    template<class T>
    string to_string(const ListSequence<T>& sequence, bool isDebug);

    template<class T>
    string to_string(const Matrix<T>& matrix, bool isDebug);

    void testDynamicArray(bool isDebug);
    void testLinkedList(bool isDebug);

    void testArraySequence(bool isDebug);
    void testListSequence(bool isDebug);

    void testMatrix(bool isDebug);

    void testFunctions();
};

#endif