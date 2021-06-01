#include "iostream"
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "ListSequence.h"
#include "ListSequence.cpp"
#include "ArraySequence.h"
#include "ArraySequence.cpp"
#include "tests.h"
#include "tests.cpp"

using namespace std;

int main() {
    Tests tests;
    tests.testDynamicArray();
    tests.testLinkedList();
    tests.testArraySequence();
    tests.testListSequence();
    system("pause");
    return 0;
}