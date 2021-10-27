#include <iostream>
#include <ctime>
#include "Sorter/Sorter.h"
#include "Sorter/Sorter.cpp"
#include "../../../semester-2/lab-2/src/DynamicArray/DynamicArray.h"
#include "../../../semester-2/lab-2/src/DynamicArray/DynamicArray.cpp"
#include "../../../semester-2/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../semester-2/lab-2/src/ArraySequence/ArraySequence.cpp"

// This tells Catch2 to provide a main() - do this only once in cpp file
#define CATCH_CONFIG_MAIN

using namespace std;

int comp(int num1, int num2) {
    if (num1 > num2) {
        cout << num1 << " > " << num2 << endl;
        return 1;
    }
    if (num1 < num2) {
        cout << num1 << " < " << num2 << endl;
        return -1;
    }
    return 0;
}

template<class T>
void setRandomNumbers(ArraySequence<T> &sequence, int count) {
    for (int i(0); i < count; i++) 
        sequence.append(rand() % 200 - 100);
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
