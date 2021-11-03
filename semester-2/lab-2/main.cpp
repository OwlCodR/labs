#include "iostream"
#include "src/DynamicArray/DynamicArray.h"
#include "src/DynamicArray/DynamicArray.cpp"
#include "src/LinkedList/LinkedList.h"
#include "src/LinkedList/LinkedList.cpp"
#include "src/ListSequence/ListSequence.h"
#include "src/ListSequence/ListSequence.cpp"
#include "src/ArraySequence/ArraySequence.h"
#include "src/ArraySequence/ArraySequence.cpp"
#include "src/Matrix/Matrix.h"
#include "src/Matrix/Matrix.cpp"
#include "../Tests/Tests.h"
#include "../Tests/Tests.cpp"

using namespace std;

int main() {
    Tests tests;
    tests.testDynamicArray(true);
    tests.testLinkedList(true);
    tests.testArraySequence(true);
    tests.testListSequence(true);
    tests.testMatrix(true);
    // tests.testFunctions();
    return 0;
}