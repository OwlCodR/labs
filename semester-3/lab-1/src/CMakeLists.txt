project(lab)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
# file(GLOB INCLUDES "include/*.hpp")
file(GLOB LAB_2 "../../semester-2/lab-2/include/*.hpp")

add_executable(lab ../main.cpp ${HEADERS} ${SOURCES} ${LAB_2})
# target_include_directories(lab PRIVATE ${PROJECT_SOURCE_DIR}/include)
