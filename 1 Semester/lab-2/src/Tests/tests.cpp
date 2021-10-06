#include "Tests.h"

template<class T>
void Tests::print(const DynamicArray<T>& array, bool isDebug) {
    if (isDebug)
        cout << "DynamicArray[" << array.getSize() << "]: ";
    for (int i(0); i < array.getSize(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<class T>
void Tests::print(const LinkedList<T>& list, bool isDebug) {
    if (isDebug)
        cout << "LinkedList[" << list.getSize() << "]: ";

    Node<T>* node = list.getFirstNode();
    for (int i(0); i < list.getSize(); i++) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

template<class T>
void Tests::print(const ArraySequence<T>& sequence, bool isDebug) {
    print(sequence.getDynamicArray(), isDebug);
}

template<class T>
void Tests::print(const ListSequence<T>& sequence, bool isDebug) {
    print(sequence.getLinkedList(), isDebug);
}

template<class T>
void Tests::print(const Matrix<T>& mat, bool isDebug) {
    if (isDebug)
        cout << endl << "Matrix[" << mat.getSize() << "]:" << endl;

    for (int i(0); i < mat.getSize(); i++) {
        for (int j(0); j < mat.getSize(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
string Tests::to_string(const DynamicArray<T>& array, bool isDebug) {
    if (isDebug)
        print(array, isDebug);
    string s = "";

    for (int i(0); i < array.getSize(); i++) {
        s += std::to_string(array[i]);
        if (i != array.getSize() - 1)
            s += " ";
    }

    return s;
}

template<class T>
string Tests::to_string(const LinkedList<T>& list, bool isDebug) {
    if (isDebug)
        print(list, isDebug);
    string s = "";

    Node<T>* node = list.getFirstNode();
    for (int i(0); i < list.getSize(); i++) {
        s += std::to_string(node->value);
        if (i != list.getSize() - 1)
            s += " ";
        node = node->next;
    }

    return s;
}

template<class T>
string Tests::to_string(const ArraySequence<T>& sequence, bool isDebug) {
    if (isDebug)
        print(sequence, isDebug);
    return to_string(sequence.getDynamicArray(), isDebug);
}

template<class T>
string Tests::to_string(const ListSequence<T>& sequence, bool isDebug) {
    if (isDebug)
        print(sequence, isDebug);
    return to_string(sequence.getLinkedList(), isDebug);
}

template<class T>
string Tests::to_string(const Matrix<T>& mat, bool isDebug) {
    if (isDebug)
        print(mat, isDebug);

    string s = "";
    for (int i(0); i < mat.getSize(); i++) {
        for (int j(0); j < mat.getSize(); j++) {
            s += std::to_string(mat[i][j]);
            if (j != mat.getSize() - 1)
                s += " ";
        }
        if (i != mat.getSize() - 1)
            s += "\n";
    }
    // cout << s << endl;
    return s;
}

void Tests::testDynamicArray(bool isDebug) {
    cout << "\nDYNAMIC ARRAY TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    DynamicArray<int> dynamicArray(array, size);    
    print(dynamicArray, isDebug);

    assert(to_string(dynamicArray, true) == "1 2 3 4 5 6 7 8 9 10");
    assert(dynamicArray.getSize() == size);
    assert(dynamicArray.get(0) == 1);
    assert(dynamicArray.get(5) == 6);
    // assert(dynamicArray.get(100) == 6);

    dynamicArray.set(9, 100);
    // dynamicArray.set(1000, 100);
    assert(to_string(dynamicArray, true) == "1 2 3 4 5 6 7 8 9 100");

    dynamicArray.set(0, 100);
    assert(to_string(dynamicArray, true) == "100 2 3 4 5 6 7 8 9 100");

    dynamicArray.resize(20);
    assert(dynamicArray.getSize() == 20);

    dynamicArray.resize(5);
    assert(to_string(dynamicArray, true) == "100 2 3 4 5");
}

void Tests::testLinkedList(bool isDebug) {
    cout << "\nLINKED LIST TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList<int> linkedList(array, size);
    print(linkedList, isDebug);

    assert(to_string(linkedList, true) == "1 2 3 4 5 6 7 8 9 10");
    assert(linkedList.getSize() == size);
    assert(linkedList.get(0) == 1);
    assert(linkedList.get(5) == 6);
    // assert(linkedList.get(100) == 6);
    assert(linkedList.getFirst() == 1);
    assert(linkedList.getLast() == 10);

    linkedList.insertAt(10, 100);
    // linkedList.insertAt(1000, 100);
    assert(to_string(linkedList, true) == "1 2 3 4 5 6 7 8 9 10 100");

    linkedList.insertAt(0, 100);
    assert(to_string(linkedList, true) == "100 1 2 3 4 5 6 7 8 9 10 100");

    linkedList.insertAt(5, 100);
    assert(to_string(linkedList, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");


    LinkedList<int>* subLinkedList1 = linkedList.getSubList(0, 5);
    assert(subLinkedList1->getSize() == 5);
    assert(to_string(*subLinkedList1, true) == "100 1 2 3 4");


    LinkedList<int>* subLinkedList2 = linkedList.getSubList(5, 13);
    assert(subLinkedList2->getSize() == 8);
    assert(to_string(*subLinkedList2, true) == "100 5 6 7 8 9 10 100");


    LinkedList<int>* concat = subLinkedList1->concat(subLinkedList2);
    assert(concat->getSize() == 13);
    assert(to_string(*concat, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}

void Tests::testArraySequence(bool isDebug) {
    cout << "\nARRAY SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ArraySequence<int> arraySequence(array, size);
    
    assert(to_string(arraySequence, true) == "1 2 3 4 5 6 7 8 9 10");
    assert(arraySequence.getSize() == size);
    assert(arraySequence.get(0) == 1);
    assert(arraySequence.get(5) == 6);
    // assert(arraySequence.get(100) == 6);
    assert(arraySequence.getFirst() == 1);
    assert(arraySequence.getLast() == 10);

    arraySequence.insertAt(10, 100);
    // assert(arraySequence.insertAt(100) == 6);
    assert(to_string(arraySequence, true) == "1 2 3 4 5 6 7 8 9 10 100");

    arraySequence.insertAt(0, 100);
    assert(to_string(arraySequence, true) == "100 1 2 3 4 5 6 7 8 9 10 100");

    arraySequence.insertAt(5, 100);
    assert(to_string(arraySequence, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");

    ArraySequence<int>* subArraySequence1 = (ArraySequence<int>*) arraySequence.getSubSequence(0, 5);
    assert(subArraySequence1->getSize() == 5);
    assert(to_string(*subArraySequence1, true) == "100 1 2 3 4");

    ArraySequence<int>* subArraySequence2 = (ArraySequence<int>*) arraySequence.getSubSequence(5, 13);
    assert(subArraySequence2->getSize() == 8);
    assert(to_string(*subArraySequence2, true) == "100 5 6 7 8 9 10 100");

    ArraySequence<int>* concat = (ArraySequence<int>*) subArraySequence1->concat((Sequence<int>*) subArraySequence2);
    assert(concat->getSize() == 13);
    assert(to_string(*concat, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}

void Tests::testListSequence(bool isDebug) {
    cout << "\nLIST SEQUENCE TEST" << endl;

    int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ListSequence<int> listSequence(array, size);

    print(listSequence, isDebug);
    assert(to_string(listSequence, true) == "1 2 3 4 5 6 7 8 9 10");
    assert(listSequence.getSize() == size);
    assert(listSequence.get(0) == 1);
    assert(listSequence.get(5) == 6);
    assert(listSequence.getFirst() == 1);
    assert(listSequence.getLast() == 10);

    listSequence.insertAt(10, 100);
    // assert(listSequence.insertAt(100) == 6);
    assert(to_string(listSequence, true) == "1 2 3 4 5 6 7 8 9 10 100");

    listSequence.insertAt(0, 100);
    assert(to_string(listSequence, true) == "100 1 2 3 4 5 6 7 8 9 10 100");

    listSequence.insertAt(5, 100);
    assert(to_string(listSequence, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");

    ListSequence<int>* subListSequence1 = (ListSequence<int>*) listSequence.getSubSequence(0, 5);
    assert(subListSequence1->getSize() == 5);
    assert(to_string(*subListSequence1, true) == "100 1 2 3 4");

    ListSequence<int>* subListSequence2 = (ListSequence<int>*) listSequence.getSubSequence(5, 13);
    assert(subListSequence2->getSize() == 8);
    assert(to_string(*subListSequence2, true) == "100 5 6 7 8 9 10 100");

    ListSequence<int>* concat = (ListSequence<int>*) subListSequence1->concat((Sequence<int>*) subListSequence2);
    assert(concat->getSize() == 13);
    assert(to_string(*concat, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}

void Tests::testMatrix(bool isDebug) {
    cout << "\nMATRIX TEST" << endl;

    int size = 9;
    int **array = new int*[3];
    for(int i(0); i < size; i++) {
        array[i] = new int[3];
        for(int j(0); j < size; j++) {
            array[i][j] = (int) (i * ((int) sqrt(size)) + j + 1);
        }
    }

    Matrix<int> matrix(array, (int) sqrt(size));

    print(matrix, isDebug);
    assert(to_string(matrix, true) == "1 2 3\n4 5 6\n7 8 9");
    assert(matrix.getSize() == (int) sqrt(size));

    assert(matrix.get(0, 0) == 1);
    assert(matrix.get(0, 2) == 3);
    assert(matrix.get(2, 2) == 9);
    assert(matrix.get(1, 1) == 5);
    // assert(matrix.get(100, 100) == 5);

    assert(matrix.getColumnsNorm() == 18);
    assert(matrix.getRowsNorm() == 24);
    assert(matrix.getNorm() == 16);

    assert(to_string(matrix.sumColumn(0, 1), true) == "3 2 3\n9 5 6\n15 8 9");
    assert(to_string(matrix.sumRow(0, 1), true) == "5 7 9\n4 5 6\n7 8 9");
    assert(to_string(matrix.sumMultipliedColumn(1, 2, 2), true) == "1 8 3\n4 17 6\n7 26 9");
    assert(to_string(matrix.sumMultipliedRow(2, 0, -1), true) == "1 2 3\n4 5 6\n6 6 6");
    assert(to_string(matrix.swapRows(0, 2), true) == "7 8 9\n4 5 6\n1 2 3");
    assert(to_string(matrix.swapColumns(1, 0), true) == "2 1 3\n5 4 6\n8 7 9");
    assert(to_string(matrix.transpose(), true) == "1 4 7\n2 5 8\n3 6 9");
    
    assert(to_string(matrix * matrix, true) == "30 36 42\n66 81 96\n102 126 150");
    assert(to_string(matrix * 2, true) == "2 4 6\n8 10 12\n14 16 18");
    assert(to_string(matrix + matrix, true) == "2 4 6\n8 10 12\n14 16 18");
    assert(to_string(matrix - matrix, true) == "0 0 0\n0 0 0\n0 0 0");

    matrix.makeZero();
    assert(to_string(matrix, true) == "0 0 0\n0 0 0\n0 0 0");

    Matrix<int> input_matrix;
    input_matrix.input();
    print(input_matrix, true);

    Matrix<int> gen_matrix;
    gen_matrix.generate(3, -5, 10);
    print(gen_matrix, true);
}

void Tests::testFunctions() {
    Matrix<int> gen_matrix;
    // print(gen_matrix, true);
    ofstream out;
    clock_t start, end;

    out.open("time.txt");

    if (out.is_open())
    {
        for (int i(100); i <= 1000; i += 100) {
            gen_matrix.generate(i, -10, 10);

            start = clock();
            gen_matrix.getNorm();
            end = clock();

            double seconds = (double) (end - start);
            out << i << ";" << seconds << ";" << endl;
        }
    }
}