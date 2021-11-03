#include <iostream>
#include <ctime>
#include "include/Sorter.hpp"
#include "../../semester-2/lab-2/include/DynamicArray.hpp"
#include "../../semester-2/lab-2/include/ArraySequence.hpp"
#include "../../semester-2/lab-2/include/LinkedList.hpp"
#include "../../semester-2/lab-2/include/ListSequence.hpp"

// This tells Catch2 to provide a main() - do this only once in cpp file
// #define CATCH_CONFIG_MAIN
// #include "../include/catch.hpp"

using namespace std;

int comp(int num1, int num2) {
    if (num1 > num2) 
        return 1;

    if (num1 < num2) 
        return -1;

    return 0;
}

template<class T>
void setRandomNumbers(ArraySequence<T> &sequence, int count) {
    for (int i(0); i < count; i++) 
        sequence.append(rand() % 200 - 100);
}

template<class T>
void printSequence(ArraySequence<T>& sequence) {
    for (int i(0); i < sequence.getSize(); i++)
        cout << sequence.get(i) << " ";
}

int main()
{
    srand(time(nullptr));

    ArraySequence<int> sequence;

    setRandomNumbers(sequence, 10);

    Sorter<int>::quick_sort(&sequence, comp);
    printSequence(sequence);

    return 0;
}
