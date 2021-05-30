#include "tests.h"

void Tests::testDynamicArray() {
    cout << "\nDYNAMIC ARRAY TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    DynamicArray<int> dynamicArray(array, size);
    // DynamicArray<int> dynamicArray(dynamicArray1);
    // DynamicArray<int> dynamicArray(size);
    
    dynamicArray.print(true);

    assert(dynamicArray.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(dynamicArray.getSize() == size);

    /// GET TESTS ///
        assert(dynamicArray.get(0) == 1);
        assert(dynamicArray.get(5) == 6);
        // assert(dynamicArray.get(10) == -1);
        // assert(dynamicArray.get(-5) == -1);
    /// GET TESTS ///

    /// SET TESTS ///
        dynamicArray.set(9, 100);
        assert(dynamicArray.to_string() == "1 2 3 4 5 6 7 8 9 100");

        dynamicArray.set(0, 100);
        assert(dynamicArray.to_string() == "100 2 3 4 5 6 7 8 9 100");
        // dynamicArray1.set(-10, 100);
        // dynamicArray1.set(20, 100);
    /// SET TESTS ///

    /// RESIZE TESTS ///
        dynamicArray.resize(20);
        dynamicArray.print(true);

        assert(dynamicArray.getSize() == 20);

        dynamicArray.resize(5);
        assert(dynamicArray.to_string() == "100 2 3 4 5");
        // dynamicArray1.resize(-10);
    /// RESIZE TESTS ///
}

void Tests::testLinkedList() {
    cout << "\nLINKED LIST TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList<int> linkedList(array, size);
    // LinkedList<int> linkedList(linkedList);
    // LinkedList<int> linkedList();
    
    linkedList.print(true);

    assert(linkedList.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(linkedList.getSize() == size);

    /// GET TESTS ///
        assert(linkedList.get(0) == 1);
        assert(linkedList.get(5) == 6);
        assert(linkedList.getFirst() == 1);
        assert(linkedList.getLast() == 10);
        // assert(linkedList.get(20) == -1);
        // assert(linkedList.get(-5) == -1);
    /// GET TESTS ///

    /// INSERT TESTS ///
        linkedList.insertAt(10, 100);
        assert(linkedList.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

        linkedList.insertAt(0, 100);
        assert(linkedList.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

        linkedList.insertAt(5, 100);
        assert(linkedList.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
        // linkedList.set(-10, 100);
        // linkedList.set(20, 100);
    /// INSERT TESTS ///

    /// GET SUB LIST TESTS ///
        LinkedList<int>* subLinkedList1 = linkedList.getSubList(0, 5);
        // LinkedList<int>* subLinkedList1 = linkedList.getSubList(20, -2);
        subLinkedList1->print(true);

        assert(subLinkedList1->getSize() == 5);
        assert(subLinkedList1->to_string() == "100 1 2 3 4");

        LinkedList<int>* subLinkedList2 = linkedList.getSubList(5, 13);
        // LinkedList<int>* subLinkedList2 = linkedList.getSubList(0, -2);
        subLinkedList2->print(true);

        assert(subLinkedList2->getSize() == 8);
        assert(subLinkedList2->to_string() == "100 5 6 7 8 9 10 100");
    /// GET SUB LIST TESTS ///

    /// CONCAT TESTS ///
        LinkedList<int>* concat = subLinkedList1->concat(subLinkedList2);
        concat->print(true);

        assert(concat->getSize() == 13);
        assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    /// CONCAT TESTS ///
}