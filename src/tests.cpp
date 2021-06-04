#include "tests.h"

void Tests::testDynamicArray(bool debug) {
    cout << "\nDYNAMIC ARRAY TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    DynamicArray<int> dynamicArray(array, size);
    // DynamicArray<int> dynamicArray(dynamicArray1);
    // DynamicArray<int> dynamicArray(size);
    
    dynamicArray.print(debug);

    assert(dynamicArray.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(dynamicArray.getSize() == size);



    assert(dynamicArray.get(0) == 1);
    assert(dynamicArray.get(5) == 6);
    // assert(dynamicArray.get(10) == -1);
    // assert(dynamicArray.get(-5) == -1);



    dynamicArray.set(9, 100);
    dynamicArray.print(debug);
    assert(dynamicArray.to_string() == "1 2 3 4 5 6 7 8 9 100");

    dynamicArray.set(0, 100);
    dynamicArray.print(debug);
    assert(dynamicArray.to_string() == "100 2 3 4 5 6 7 8 9 100");
    // dynamicArray1.set(-10, 100);
    // dynamicArray1.set(20, 100);



    dynamicArray.resize(20);
    dynamicArray.print(debug);
    assert(dynamicArray.getSize() == 20);

    dynamicArray.resize(5);
    dynamicArray.print(debug);
    assert(dynamicArray.to_string() == "100 2 3 4 5");
    // dynamicArray1.resize(-10);
}

void Tests::testLinkedList(bool debug) {
    cout << "\nLINKED LIST TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList<int> linkedList1(array, size);
    LinkedList<int> linkedList(linkedList1);
    // LinkedList<int> linkedList;
    
    linkedList.print(debug);

    assert(linkedList.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(linkedList.getSize() == size);



    assert(linkedList.get(0) == 1);
    assert(linkedList.get(5) == 6);
    assert(linkedList.getFirst() == 1);
    assert(linkedList.getLast() == 10);
    // assert(linkedList.get(20) == -1);
    // assert(linkedList.get(-5) == -1);



    linkedList.insertAt(10, 100);
    linkedList.print(debug);
    assert(linkedList.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

    linkedList.insertAt(0, 100);
    linkedList.print(debug);
    assert(linkedList.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

    linkedList.insertAt(5, 100);
    linkedList.print(debug);
    assert(linkedList.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    // linkedList.set(-10, 100);
    // linkedList.set(20, 100);



    LinkedList<int>* subLinkedList1 = linkedList.getSubList(0, 5);
    // LinkedList<int>* subLinkedList1 = linkedList.getSubList(20, -2);
    subLinkedList1->print(debug);
    assert(subLinkedList1->getSize() == 5);
    assert(subLinkedList1->to_string() == "100 1 2 3 4");

    LinkedList<int>* subLinkedList2 = linkedList.getSubList(5, 13);
    // LinkedList<int>* subLinkedList2 = linkedList.getSubList(0, -2);
    subLinkedList2->print(debug);
    assert(subLinkedList2->getSize() == 8);
    assert(subLinkedList2->to_string() == "100 5 6 7 8 9 10 100");



    LinkedList<int>* concat = subLinkedList1->concat(subLinkedList2);
    concat->print(debug);

    assert(concat->getSize() == 13);
    assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}

void Tests::testArraySequence(bool debug) {
    cout << "\nARRAY SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ArraySequence<int> arraySequence(array, size);
    // ArraySequence<int> arraySequence(arraySequence);
    // ArraySequence<int> arraySequence();
    
    arraySequence.print(debug);
    assert(arraySequence.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(arraySequence.getSize() == size);



    assert(arraySequence.get(0) == 1);
    assert(arraySequence.get(5) == 6);
    assert(arraySequence.getFirst() == 1);
    assert(arraySequence.getLast() == 10);
    // assert(arraySequence.get(20) == -1);
    // assert(arraySequence.get(-5) == -1);



    arraySequence.insertAt(10, 100);
    arraySequence.print(debug);
    assert(arraySequence.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

    arraySequence.insertAt(0, 100);
    arraySequence.print(debug);
    assert(arraySequence.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

    arraySequence.insertAt(5, 100);
    arraySequence.print(debug);
    assert(arraySequence.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    // linkedList.set(-10, 100);
    // linkedList.set(20, 100);



    ArraySequence<int>* subArraySequence1 = (ArraySequence<int>*) arraySequence.getSubSequence(0, 5);
    // LinkedList<int>* subArraySequence1 = arraySequence.getSubList(20, -2);
    subArraySequence1->print(debug);
    assert(subArraySequence1->getSize() == 5);
    assert(subArraySequence1->to_string() == "100 1 2 3 4");

    ArraySequence<int>* subArraySequence2 = (ArraySequence<int>*) arraySequence.getSubSequence(5, 13);
    // LinkedList<int>* subArraySequence2 = arraySequence.getSubList(0, -2);
    subArraySequence2->print(debug);
    assert(subArraySequence2->getSize() == 8);
    assert(subArraySequence2->to_string() == "100 5 6 7 8 9 10 100");



    ArraySequence<int>* concat = (ArraySequence<int>*) subArraySequence1->concat((Sequence<int>*) subArraySequence2);
    concat->print(debug);
    assert(concat->getSize() == 13);
    assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}

void Tests::testListSequence(bool debug) {
    cout << "\nLIST SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ListSequence<int> listSequence(array, size);
    // ListSequence<int> listSequence(listSequence);
    // ListSequence<int> listSequence();

    listSequence.print(debug);
    assert(listSequence.to_string() == "1 2 3 4 5 6 7 8 9 10");
    assert(listSequence.getSize() == size);



    assert(listSequence.get(0) == 1);
    assert(listSequence.get(5) == 6);
    assert(listSequence.getFirst() == 1);
    assert(listSequence.getLast() == 10);
    // assert(listSequence.get(20) == -1);
    // assert(listSequence.get(-5) == -1);



    listSequence.insertAt(10, 100);
    listSequence.print(debug);
    assert(listSequence.to_string() == "1 2 3 4 5 6 7 8 9 10 100");

    listSequence.insertAt(0, 100);
    listSequence.print(debug);
    assert(listSequence.to_string() == "100 1 2 3 4 5 6 7 8 9 10 100");

    listSequence.insertAt(5, 100);
    listSequence.print(debug);
    assert(listSequence.to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
    // listSequence.set(-10, 100);
    // listSequence.set(20, 100);



    ListSequence<int>* subListSequence1 = (ListSequence<int>*) listSequence.getSubSequence(0, 5);
    // ListSequence<int>* subListSequence1 = listSequence.getSubList(20, -2);
    subListSequence1->print(debug);
    assert(subListSequence1->getSize() == 5);
    assert(subListSequence1->to_string() == "100 1 2 3 4");

    ListSequence<int>* subListSequence2 = (ListSequence<int>*) listSequence.getSubSequence(5, 13);
    // ListSequence<int>* subListSequence2 = subListSequence1.getSubList(0, -2);
    subListSequence2->print(debug);
    assert(subListSequence2->getSize() == 8);
    assert(subListSequence2->to_string() == "100 5 6 7 8 9 10 100");



    ListSequence<int>* concat = (ListSequence<int>*) subListSequence1->concat((Sequence<int>*) subListSequence2);
    concat->print(debug);
    assert(concat->getSize() == 13);
    assert(concat->to_string() == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}