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
    DynamicArray();
    DynamicArray(const DynamicArray<T>& array);

    ~DynamicArray();

    T get(int index);
    T get(const int index) const;
    int getSize() const;

    void set(int index, T value);
    void resize(int newSize);

    T& operator[](int index);
    T operator[](int index) const;

    void print(bool debug);
    string to_string();

    // Check size errors!
private:
    T* array;
    int size;
};

#endif