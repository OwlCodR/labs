#include "DynamicArray.h"

template<class T> 
DynamicArray<T>::DynamicArray(T* items, int count) {
    size = count;
    capacity = count * 2;
    array = new T[capacity];
    for (int i(0); i < size; i++) {
        array[i] = items[i];
    }
}


template<class T> 
DynamicArray<T>::DynamicArray(int count) {
    size = count;
    capacity = count * 2;
    array = new T[capacity];
}

template<class T> 
DynamicArray<T>::DynamicArray() {
    array = nullptr;
    size = 0;
    capacity = 0;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template<class T> 
DynamicArray<T>::DynamicArray(const DynamicArray<T>& const_array) {
    array = new T[const_array.getSize()];
    size = const_array.getSize();
    capacity = const_array.getCapacity();
    
    for (int i(0); i < size; i++) {
        array[i] = const_array[i];
    }
}

template<class T> 
T DynamicArray<T>::get(int index) {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else
            return array[index];
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T> 
T DynamicArray<T>::get(int index) const {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else
            return array[index];
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T> 
int DynamicArray<T>::getSize() const {
    return this->size;
}

template<class T>
int DynamicArray<T>::getCapacity() const {
    return this->capacity;
}

template<class T>
void DynamicArray<T>::set(int index, T value) {
    try
    {
        if (index < 0 || index >= capacity)
            throw "IndexOutOfRange";
        else {
            array[index] = value;
            
            if (index >= size)
                size++;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
    }
}


template<class T> 
void DynamicArray<T>::resize(int newSize) {
    try
    {
        if (newSize <= 0) 
            throw "IndexOutOfRange";
        else if (newSize != size)
        {
            capacity = newSize * 2;

            T* new_array = new T[capacity];

            for (int i(0); i < newSize; i++) {
                if (i < size)
                    new_array[i] = array[i];
            }

            array = new_array;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
    }
}

template<class T> 
T& DynamicArray<T>::operator[](int index) {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else
            return array[index];
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T> 
T DynamicArray<T>::operator[](int index) const {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else
            return array[index];
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}