#ifndef TESTS_H
#define TESTS_H

#include "iostream"
#include <cassert>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"

using namespace std;

class Tests {
public:
    void testDynamicArray(bool debug);
    void testLinkedList(bool debug);

    void testArraySequence(bool debug);
    void testListSequence(bool debug);
};

#endif