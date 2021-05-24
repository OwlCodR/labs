#include "iostream"
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "tests.h"
#include "tests.cpp"

using namespace std;

int main() {
    Tests tests;
    tests.testDynamicArray();
    tests.testLinkedList();
    return 0;
}