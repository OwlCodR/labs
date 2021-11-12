#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
#include "src/VectorSequence/VectorSequence.h"
#include "src/Sorter/Sorter.h"
#include "../../semester-2/lab-2/include/DynamicArray.hpp"
#include "../../semester-2/lab-2/include/ArraySequence.hpp"
#include "../../semester-2/lab-2/include/LinkedList.hpp"
#include "../../semester-2/lab-2/include/ListSequence.hpp"

using namespace std;

int comp(int num1, int num2) {
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

template<class T>
void setRandomNumbers(Sequence<T>& sequence, int count) {
    for (int i(0); i < count; i++) 
        sequence.append(rand() % 100 - 100);
}

template<class T>
void printSequence(Sequence<T>& sequence) {
    for (int i(0); i < sequence.getSize(); i++)
        cout << sequence.get(i) << " ";
    cout << endl;
}

int main()
{
    srand(time(NULL));

    typedef Sorter<ArraySequence, int> Sorter;
    typedef ArraySequence<int> SomeSequence;

    SomeSequence sequence;
    setRandomNumbers(sequence, 10000);

    SomeSequence sequence2;
    setRandomNumbers(sequence2, 10000);

    //printSequence(sequence2);

    //double t = Sorter::sort_time(Sorter::quick_sort, &sequence2, comp);
    //cout << "Sort time: ";
    //printf("%.5fms\n", t);

    cout << "Difference: " << Sorter::sort_time_difference(Sorter::quick_sort, Sorter::quick_sort, &sequence, comp);

    //printSequence(sequence2);
    return 0;
}
