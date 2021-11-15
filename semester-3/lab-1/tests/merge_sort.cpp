#define BOOST_TEST_MODULE Merge Sort Tests 

#include <boost/test/included/unit_test.hpp>

typedef std::tuple<int, float, double> test_types;

BOOST_AUTO_TEST_SUITE(array_sequence_tests)

    BOOST_AUTO_TEST_CASE_TEMPLATE(big_size, T, test_types)
    {
        BOOST_CHECK(2 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(not_sorted, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(already_sorted, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(already_reverse_sorted, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(empty, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(one_element, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(check_max_complexity, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_direct_sort, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_reverse_sort, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

    BOOST_AUTO_TEST_CASE_TEMPLATE(compare_unique_sort, T, test_types)
    {
        BOOST_CHECK(1 == 2);
    }

BOOST_AUTO_TEST_SUITE_END()