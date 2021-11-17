find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(QUICK_SORT_SOURCES quick_sort.cpp)
set(MERGE_SORT_SOURCES merge_sort.cpp)

set(QUICK_SORT_TEST quick_sort_test)
set(MERGE_SORT_TEST merge_sort_test)

add_executable(${QUICK_SORT_TEST} ${QUICK_SORT_SOURCES})
add_executable(${MERGE_SORT_TEST} ${MERGE_SORT_SOURCES})

target_link_libraries(${QUICK_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})
target_link_libraries(${MERGE_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})

add_test(${QUICK_SORT_TEST} ${QUICK_SORT_TEST})
add_test(${MERGE_SORT_TEST} ${MERGE_SORT_TEST})
