#define BOOST_TEST_MODULE Simple Insertion Sort Tests 
#define BOOST_TIMEOUT 60

#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <functional>
#include <complex>
#include "../../src/VectorSequence/VectorSequence.h"
#include "../../src/Sorter/Sorter.h"
#include "../../../../semester-2/lab-2/include/DynamicArray.hpp"
#include "../../../../semester-2/lab-2/include/LinkedList.hpp"
#include "../../../../semester-2/lab-2/include/ArraySequence.hpp"
#include "../../../../semester-2/lab-2/include/ListSequence.hpp"

typedef std::tuple<int, float, double> test_types;

int inverse_comp(int num1, int num2) {
    if (num1 > num2) return -1;
    if (num1 < num2) return 1;
    return 0;
}

int direct_comp(int num1, int num2) {
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

template<class T>
void printSequence(Sequence<T>& seq) {
    for (int i(0); i < seq.getSize(); i++) {
        cout << seq.get(i) << " ";
    }
    cout << endl;
}

template<class T>
void setRandElements(Sequence<T>& seq, int count, int min, int max) {
    for (int i(0); i < count; i++) {
        seq.append(rand() % (max - min) + min);
    }
}

template<class T>
bool isSequenceSorted(Sequence<T>& seq, function<int(T, T)> comp) {
    for (int i(0); i < seq.getSize() - 1; i++)
        if (comp(seq.get(i + 1), seq.get(i)) == -1)
            return false;

    return true;
}

BOOST_AUTO_TEST_SUITE(list_sequence_tests)

BOOST_AUTO_TEST_CASE_TEMPLATE(direct_sort, T, test_types)
{
    ListSequence<T> sequence;

    T not_sorted[5]{ 6, 1, -1, 5, 3 };
    T sorted[5]{ -1, 1, 3, 5, 6 };

    for (int i(0); i < 5; i++)
        sequence.append(not_sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(inverse_sort, T, test_types)
{
    ListSequence<T> sequence;

    T not_sorted[5]{ 1, 6, -1, 5, 3 };
    T sorted[5]{ 6, 5, 3, 1, -1 };

    for (int i(0); i < 5; i++)
        sequence.append(not_sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, inverse_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(not_sorted, T, test_types)
{
    ListSequence<T> sequence;

    T not_sorted[5]{ 4, 1, 2, 5, 3 };
    T sorted[5]{ 1, 2, 3, 4, 5 };

    for (int i(0); i < 5; i++)
        sequence.append(not_sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(already_sorted, T, test_types)
{
    ListSequence<T> sequence;

    T sorted[5]{ 1, 2, 3, 4, 5 };

    for (int i(0); i < 5; i++)
        sequence.append(sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(already_inverse_sorted, T, test_types)
{
    ListSequence<T> sequence;

    T not_sorted[5]{ 5, 4, 3, 2, 1 };
    T sorted[5]{ 1, 2, 3, 4, 5 };

    for (int i(0); i < 5; i++)
        sequence.append(not_sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(empty, T, test_types)
{
    ListSequence<T> sequence;

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 0);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(one_element, T, test_types)
{
    ListSequence<T> sequence;

    sequence.append(0);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 1);
    BOOST_CHECK(sequence.get(0) == 0);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(all_same_elements, T, test_types)
{
    ListSequence<T> sequence;

    T sorted[5]{ 1, 1, 1, 1, 1 };

    for (int i(0); i < 5; i++)
        sequence.append(sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(same_elements, T, test_types)
{
    ListSequence<T> sequence;

    T not_sorted[5]{ 1, 2, 1, 2, 1 };
    T sorted[5]{ 1, 1, 1, 2, 2 };

    for (int i(0); i < 5; i++)
        sequence.append(sorted[i]);

    Sorter<ListSequence, T>::insertion_sort(&sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 5);

    for (int i(0); i < 5; i++) {
        BOOST_CHECK(sequence.get(i) == sorted[i]);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(check_sort_time_10k, T, test_types)
{
    ListSequence<T> sequence;

    setRandElements(sequence, 10000, -100, 100);

    typedef Sorter<ListSequence, T> Sorter;

    double sort_time = Sorter::sort_time(Sorter::insertion_sort, &sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 10000);
    BOOST_CHECK(sort_time < 5.0);

    std::cout << "ListSequence Insertion Sort 10k time = " << sort_time << "ms" << endl;

    BOOST_CHECK(isSequenceSorted<T>(sequence, direct_comp) == true);
}

// BOOST_AUTO_TEST_CASE_TEMPLATE(check_sort_time_100k, T, test_types)
// {
//     if (typeid(T) == typeid(int)) {
//         ListSequence<T> sequence;

//         setRandElements(sequence, 100000, -10000, 10000);

//         typedef Sorter<ListSequence, T> Sorter;
//         double sort_time = Sorter::sort_time(Sorter::insertion_sort, &sequence, direct_comp);

//         BOOST_CHECK(sequence.getSize() == 100000);

//         BOOST_CHECK(sort_time < 500.0);

//         std::cout << "ListSequence Merge Sort 100k time = " << sort_time << "ms" << endl;

//         BOOST_CHECK(isSequenceSorted<T>(sequence, direct_comp) == true);
//     }
// }

BOOST_AUTO_TEST_CASE_TEMPLATE(sort_time_without_sort, T, test_types)
{
    ListSequence<T> sequence;

    setRandElements(sequence, 100, -100, 100);

    typedef Sorter<ListSequence, T> Sorter;
    Sorter::sort_time(Sorter::insertion_sort, sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 100);
    BOOST_CHECK(isSequenceSorted<T>(sequence, direct_comp) == false);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sort_time_with_sort, T, test_types)
{
    ListSequence<T> sequence;

    setRandElements(sequence, 100, -100, 100);

    typedef Sorter<ListSequence, T> Sorter;
    Sorter::sort_time(Sorter::insertion_sort, &sequence, direct_comp);

    BOOST_CHECK(sequence.getSize() == 100);
    BOOST_CHECK(isSequenceSorted<T>(sequence, direct_comp) == true);
}

BOOST_AUTO_TEST_SUITE_END()
