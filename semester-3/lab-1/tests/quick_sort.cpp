#define BOOST_TEST_MODULE Quick Sort Tests 

#include <boost/test/included/unit_test.hpp>

#include "../src/VectorSequence/VectorSequence.h"
#include "../src/Sorter/Sorter.h"
#include "../../../semester-2/lab-2/include/DynamicArray.hpp"
#include "../../../semester-2/lab-2/include/ArraySequence.hpp"
#include "../../../semester-2/lab-2/include/LinkedList.hpp"
#include "../../../semester-2/lab-2/include/ListSequence.hpp"

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

BOOST_AUTO_TEST_SUITE(array_sequence_tests)

    BOOST_AUTO_TEST_CASE_TEMPLATE(direct_sort, T, test_types)
    {
        ArraySequence<T> sequence;

        T not_sorted[5]{ 6, 1, -1, 5, 3 };
        T sorted[5]{ -1, 1, 3, 5, 6 };

        for (int i(0); i < 5; i++)
            sequence.append(not_sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(inverse_sort, T, test_types)
    {
        ArraySequence<T> sequence;

        T not_sorted[5]{ 6, 1, -1, 5, 3 };
        T sorted[5]{ 6, 5, 3, 1, -1 };

        for (int i(0); i < 5; i++)
            sequence.append(not_sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, inverse_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(not_sorted, T, test_types)
    {
        ArraySequence<T> sequence;

        T not_sorted[5] { 4, 1, 2, 5, 3 };
        T sorted[5] { 1, 2, 3, 4, 5 };

        for (int i(0); i < 5; i++)
            sequence.append(not_sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(already_sorted, T, test_types)
    {
        ArraySequence<T> sequence;

        T sorted[5]{ 1, 2, 3, 4, 5 };

        for (int i(0); i < 5; i++)
            sequence.append(sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(already_inverse_sorted, T, test_types)
    {
        ArraySequence<T> sequence;

        T not_sorted[5]{ 5, 4, 3, 2, 1 };
        T sorted[5]{ 1, 2, 3, 4, 5 };

        for (int i(0); i < 5; i++)
            sequence.append(not_sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(empty, T, test_types)
    {
        ArraySequence<T> sequence;

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 0);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(one_element, T, test_types)
    {
        ArraySequence<T> sequence;

        sequence.append(0);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 1);
        BOOST_CHECK(sequence.get(0) == 0);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(all_same_elements, T, test_types)
    {
        ArraySequence<T> sequence;

        T sorted[5]{ 1, 1, 1, 1, 1 };

        for (int i(0); i < 5; i++)
            sequence.append(sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(same_elements, T, test_types)
    {
        ArraySequence<T> sequence;
        
        T not_sorted[5]{ 1, 2, 1, 2, 1 };
        T sorted[5]{ 1, 1, 1, 2, 2 };

        for (int i(0); i < 5; i++)
            sequence.append(sorted[i]);

        Sorter<ArraySequence, T>::quick_sort(&sequence, direct_comp);

        BOOST_CHECK(sequence.getSize() == 5);

        for (int i(0); i < 5; i++) {
            BOOST_CHECK(sequence.get(i) == sorted[i]);
        }
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(check_time, T, test_types)
    {
        BOOST_CHECK(1 == 1);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_direct_sort, T, test_types)
    {
        BOOST_CHECK(1 == 1);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_inverse_sort, T, test_types)
    {
        BOOST_CHECK(1 == 1);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_unique_sort, T, test_types)
    {
        BOOST_CHECK(1 == 1);
    }

BOOST_AUTO_TEST_SUITE_END()