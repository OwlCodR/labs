#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <functional>
#include "../BinarySearchTree/BinarySearchTree.h"
#include "../Node/Node.h"

using namespace std;

class Tests {
public:
    void testAddTime(int size);
    void testFindTime(int size);
    void startTests();
};

#endif