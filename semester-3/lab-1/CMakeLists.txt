cmake_minimum_required(VERSION 3.5)
project(lab VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

include(CTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(src src)
add_subdirectory(tests tests)


# include(CPack)

# These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

### Catch 2
# list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
# find_package(Catch2.cmake QUIET)
# find_package(CatchAddTests.cmake QUIET)
# add_subdirectory(lib/Catch2)

# add_executable(tests tests/sort_tests.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# include(Catch2.cmake)
# # FIX TESTS AND MIGRATE CATCH2 TO CMAKE
# # catch_discover_tests(tests)

### Catch 2


