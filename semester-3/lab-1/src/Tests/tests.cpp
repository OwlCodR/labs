#define CATCH_CONFIG_MAIN

#include "../../../../catch.hpp"
#include <complex>
#include <functional>
#include <iostream>
#include <string>

#include "../../../../semester-2/lab-2/src/Sequence/Sequence.h"
#include "../../../../semester-2/lab-2/src/DynamicArray/DynamicArray.h"
#include "../../../../semester-2/lab-2/src/DynamicArray/DynamicArray.cpp"
#include "../../../../semester-2/lab-2/src/ArraySequence/ArraySequence.h"
#include "../../../../semester-2/lab-2/src/ArraySequence/ArraySequence.cpp"
#include "../../../../semester-2/lab-2/src/LinkedList/LinkedList.h"
#include "../../../../semester-2/lab-2/src/LinkedList/LinkedList.cpp"
#include "../../../../semester-2/lab-2/src/ListSequence/ListSequence.h"
#include "../../../../semester-2/lab-2/src/ListSequence/ListSequence.cpp"
#include "../../../../semester-3/lab-1/src/Sorter/Sorter.h"
#include "../../../../semester-3/lab-1/src/Sorter/Sorter.cpp"

using namespace std;

int direct_order() {
    return 0;
}

int reverse_order() {
    return 0;
}

int unique_order() {
    return 0;
}

TEMPLATE_PRODUCT_TEST_CASE("Checking the correct sorting on different types of data", "[sort]", (ArraySequence, ListSequence), (int, double)) {
    auto sort_function = Sorter<TestType>::quick_sort;

    /// @todo make more tests and fix this one

    SECTION("Already sorted sequence") {
        TestType sorted;
        sorted.append(1);
        sorted.append(2);
        sorted.append(3);
        sorted.append(4);
        sorted.append(5);

        REQUIRE(sorted.getSize() == 5);
    }

    SECTION("Reverse sorted sequence") {}

    SECTION("Unsorted sequence") {}

    SECTION("Empty sequence and sequence with size 1") {}

    SECTION("Big size of Sequence (>10.000)") {}

    SECTION("Complexity is not more than O(n^2)") {}
    
    SECTION("Different compare functions") {
        SECTION("Direct order") { 

        }

        SECTION("Reverse order") {

        }

        SECTION("Unique order") {

        }
    }

    // REQUIRE(Factorial(0) == 1);
}

// TEST_CASE("Factorials of 1 and higher are computed (pass)", "[single-file]") {
//     REQUIRE(Factorial(1) == 1);
//     REQUIRE(Factorial(2) == 2);
//     REQUIRE(Factorial(3) == 6);
//     REQUIRE(Factorial(10) == 3628800);
// }
