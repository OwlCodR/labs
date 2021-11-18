#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <ctime>
#include <string>
#include <typeinfo>

using namespace std;

template <class T>
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(int count);
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& array);

    ~DynamicArray();

    T get(int index);
    T get(const int index) const;
    int getSize() const;
    int getCapacity() const;

    void set(int index, T value);
    void resize(int newSize);

    T& operator[](int index);
    T operator[](int index) const;
    // Check size errors!
private:
    T* array;
    int capacity;
    int size;
};

#endif