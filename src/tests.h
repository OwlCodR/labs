#ifndef TESTS_H
#define TESTS_H

#include "iostream"
#include <cassert>
#include "LinkedList.h"
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "ListSequence.h"

using namespace std;

class Tests {
public:
    void testDynamicArray();
    void testLinkedList();

    void testArraySequence();
    void testListSequence();
};

#endif