cmake_minimum_required(VERSION 3.5)
project(lab VERSION 0.1.0 LANGUAGES CXX)

#enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")
file(GLOB INCLUDES "include/*.hpp")

file(GLOB LAB_2 "../../semester-2/lab-2/include/*.hpp")

### Catch 2
# list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
# find_package(Catch2.cmake QUIET)
# find_package(CatchAddTests.cmake QUIET)
# add_subdirectory(lib/Catch2)

# add_executable(tests tests/sort_tests.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# include(CTest)
# include(Catch2.cmake)
# # FIX TESTS AND MIGRATE CATCH2 TO CMAKE
# # catch_discover_tests(tests)

### Catch 2

add_executable(lab main.cpp ${HEADERS} ${SOURCES} ${LAB_2})
target_include_directories(lab PRIVATE ${PROJECT_SOURCE_DIR}/include)


