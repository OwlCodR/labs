#include "iostream"
#include "DynamicArray/DynamicArray.h"
#include "DynamicArray/DynamicArray.cpp"
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include "ListSequence/ListSequence.h"
#include "ListSequence/ListSequence.cpp"
#include "ArraySequence/ArraySequence.h"
#include "ArraySequence/ArraySequence.cpp"
#include "Tests/Tests.h"
#include "Tests/Tests.cpp"

using namespace std;

int main() {
    Tests tests;
    tests.testDynamicArray(true);
    tests.testLinkedList(true);
    tests.testArraySequence(true);
    tests.testListSequence(true);
    // system("pause");
    return 0;
}