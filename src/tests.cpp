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

void Tests::testArraySequence() {
    cout << "\nARRAY SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ArraySequence<int> arraySequence(array, size);
    // ArraySequence<int> arraySequence(arraySequence);
    // ArraySequence<int> arraySequence();
    
    arraySequence.print(true);

    assert(arraySequence.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(arraySequence.getSize() == size);

    /// GET TESTS ///
        assert(arraySequence.get(0) == 1);
        assert(arraySequence.get(5) == 6);
        assert(arraySequence.getFirst() == 1);
        assert(arraySequence.getLast() == 10);
        // assert(arraySequence.get(20) == -1);
        // assert(arraySequence.get(-5) == -1);
    /// GET TESTS ///

    /// INSERT TESTS ///
        arraySequence.insertAt(10, 100);
        assert(arraySequence.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

        arraySequence.insertAt(0, 100);
        assert(arraySequence.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

        arraySequence.insertAt(5, 100);
        assert(arraySequence.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
        // linkedList.set(-10, 100);
        // linkedList.set(20, 100);
    /// INSERT TESTS ///

    /// GET SUB LIST TESTS ///
        ArraySequence<int>* subArraySequence1 = (ArraySequence<int>*) arraySequence.getSubSequence(0, 5);
        // LinkedList<int>* subArraySequence1 = arraySequence.getSubList(20, -2);
        subArraySequence1->print(true);

        assert(subArraySequence1->getSize() == 5);
        assert(subArraySequence1->to_string() == "100 1 2 3 4");

        ArraySequence<int>* subArraySequence2 = (ArraySequence<int>*) subArraySequence1->getSubSequence(5, 13);
        // LinkedList<int>* subArraySequence2 = arraySequence.getSubList(0, -2);
        subArraySequence2->print(true);

        assert(subArraySequence2->getSize() == 8);
        assert(subArraySequence2->to_string() == "100 5 6 7 8 9 10 100");
    /// GET SUB LIST TESTS ///

    /// CONCAT TESTS ///
        ArraySequence<int>* concat = (ArraySequence<int>*) subArraySequence2->concat((Sequence<int>*) subArraySequence1);
        concat->print(true);

        assert(concat->getSize() == 13);
        assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    /// CONCAT TESTS ///
}

void Tests::testListSequence() {
    cout << "\nLIST SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ListSequence<int> listSequence(array, size);
    // ListSequence<int> listSequence(listSequence);
    // ListSequence<int> listSequence();
    
    listSequence.print(true);

    assert(listSequence.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(listSequence.getSize() == size);

    /// GET TESTS ///
        assert(listSequence.get(0) == 1);
        assert(listSequence.get(5) == 6);
        assert(listSequence.getFirst() == 1);
        assert(listSequence.getLast() == 10);
        // assert(listSequence.get(20) == -1);
        // assert(listSequence.get(-5) == -1);
    /// GET TESTS ///

    /// INSERT TESTS ///
        listSequence.insertAt(10, 100);
        assert(listSequence.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

        listSequence.insertAt(0, 100);
        assert(listSequence.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

        listSequence.insertAt(5, 100);
        assert(listSequence.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
        // listSequence.set(-10, 100);
        // listSequence.set(20, 100);
    /// INSERT TESTS ///

    /// GET SUB LIST TESTS ///
        ListSequence<int>* subListSequence1 = (ListSequence<int>*) listSequence.getSubSequence(0, 5);
        // ListSequence<int>* subListSequence1 = listSequence.getSubList(20, -2);
        subListSequence1->print(true);

        assert(subListSequence1->getSize() == 5);
        assert(subListSequence1->to_string() == "100 1 2 3 4");

        ListSequence<int>* subListSequence2 = (ListSequence<int>*) subListSequence1->getSubSequence(5, 13);
        // ListSequence<int>* subListSequence2 = subListSequence1.getSubList(0, -2);
        subListSequence2->print(true);

        assert(subListSequence2->getSize() == 8);
        assert(subListSequence2->to_string() == "100 5 6 7 8 9 10 100");
    /// GET SUB LIST TESTS ///

    /// CONCAT TESTS ///
        ListSequence<int>* concat = (ListSequence<int>*) subListSequence2->concat((Sequence<int>*) subListSequence1);
        concat->print(true);

        assert(concat->getSize() == 13);
        assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    /// CONCAT TESTS ///
}