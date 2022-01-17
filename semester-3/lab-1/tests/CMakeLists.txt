find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(ARRAY_QUICK_SORT_SOURCES ArraySequence/quick_sort.cpp)
set(ARRAY_MERGE_SORT_SOURCES ArraySequence/merge_sort.cpp)
set(ARRAY_INSERTION_SORT_SOURCES ArraySequence/insertion_sort.cpp)

set(LIST_QUICK_SORT_SOURCES ListSequence/quick_sort.cpp)
set(LIST_MERGE_SORT_SOURCES ListSequence/merge_sort.cpp)
set(LIST_INSERTION_SORT_SOURCES ListSequence/insertion_sort.cpp)


set(ARRAY_QUICK_SORT_TEST array_quick_sort_test)
set(ARRAY_MERGE_SORT_TEST array_merge_sort_test)
set(ARRAY_INSERTION_SORT_TEST array_insertion_sort_test)

set(LIST_QUICK_SORT_TEST list_quick_sort_test)
set(LIST_MERGE_SORT_TEST list_merge_sort_test)
set(LIST_INSERTION_SORT_TEST list_insertion_sort_test)


add_executable(${ARRAY_QUICK_SORT_TEST} ${ARRAY_QUICK_SORT_SOURCES})
add_executable(${ARRAY_MERGE_SORT_TEST} ${ARRAY_MERGE_SORT_SOURCES})
add_executable(${ARRAY_INSERTION_SORT_TEST} ${ARRAY_INSERTION_SORT_SOURCES})

add_executable(${LIST_QUICK_SORT_TEST} ${LIST_QUICK_SORT_SOURCES})
add_executable(${LIST_MERGE_SORT_TEST} ${LIST_MERGE_SORT_SOURCES})
# add_executable(${LIST_INSERTION_SORT_TEST} ${LIST_INSERTION_SORT_SOURCES})


target_link_libraries(${ARRAY_QUICK_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})
target_link_libraries(${ARRAY_MERGE_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})
target_link_libraries(${ARRAY_INSERTION_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})

target_link_libraries(${LIST_QUICK_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})
target_link_libraries(${LIST_MERGE_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})
#target_link_libraries(${LIST_INSERTION_SORT_TEST} ${PROJECT} ${Boost_LIBRARIES})


add_test(${ARRAY_QUICK_SORT_TEST} ${ARRAY_QUICK_SORT_TEST})
add_test(${ARRAY_MERGE_SORT_TEST} ${ARRAY_MERGE_SORT_TEST})
add_test(${ARRAY_INSERTION_SORT_TEST} ${ARRAY_INSERTION_SORT_TEST})

add_test(${LIST_QUICK_SORT_TEST} ${LIST_QUICK_SORT_TEST})
add_test(${LIST_MERGE_SORT_TEST} ${LIST_MERGE_SORT_TEST})
add_test(${LIST_INSERTION_SORT_TEST} ${LIST_INSERTION_SORT_TEST})
