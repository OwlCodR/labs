#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <ctime>
#include <string>

using namespace std;

template <class T>
class DynamicArray {
public:
    DynamicArray(T* items, int count);
    DynamicArray(int count);
    DynamicArray(const DynamicArray<T>& array);

    T get(int index);
    int getSize();

    void set(int index, T value);
    void resize(int newSize);

    T& operator[](const int index);

    void print(bool debug);
    string to_string();

    // Check size errors!
private:
    T* array;
    int size;
};

#endif