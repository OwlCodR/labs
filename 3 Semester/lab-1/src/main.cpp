#include <iostream>
#include <ctime>
#include "Sorter/Sorter.h"
#include "Sorter/Sorter.cpp"
#include "../../../2 Semester/lab-2/src/DynamicArray/DynamicArray.h"
#include "../../../2 Semester/lab-2/src/DynamicArray/DynamicArray.cpp"
#include "../../../2 Semester/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../2 Semester/lab-2/src/ArraySequence/ArraySequence.cpp"

using namespace std;

/// @todo Change bool to int (0 - >, 1 - <, 2 - ==) 
bool comp(int num1, int num2) {
    return num1 > num2;
}

template<class T>
void setRandomNumbers(ArraySequence<T> &sequence, int count) {
    for (int i(0); i < count; i++) {
        sequence.append(rand() % 200 - 100);
    }
}

template<class T>
void printSequence(ArraySequence<T>& sequence) {
    for (int i(0); i < sequence.getSize(); i++) {
        cout << sequence.get(i) << " ";
    }
}

int main() {
    srand(time(nullptr));

    ArraySequence<int> sequence;

    setRandomNumbers(sequence, 10);

    Sorter<int>::quick_sort(&sequence, comp);
    printSequence(sequence);

    return 0;
}
