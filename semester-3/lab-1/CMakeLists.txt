cmake_minimum_required(VERSION 3.5)
project(lab VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

include(CTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(src src)
add_subdirectory(tests tests)

