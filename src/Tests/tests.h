#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cassert>
#include "../DynamicArray/DynamicArray.h"
#include "../LinkedList/LinkedList.h"
#include "../ArraySequence/ArraySequence.h"
#include "../ListSequence/ListSequence.h"

using namespace std;

class Tests {
public:
    void testDynamicArray(bool debug);
    void testLinkedList(bool debug);

    void testArraySequence(bool debug);
    void testListSequence(bool debug);

    void testMatrix(bool debug);
};

#endif