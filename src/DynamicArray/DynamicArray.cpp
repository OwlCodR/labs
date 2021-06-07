#include "DynamicArray.h"

template<class T> 
DynamicArray<T>::DynamicArray(T* items, int count) {
    array = new T[count];
    size = count;
    for (int i(0); i < size; i++) {
        array[i] = items[i];
    }
}


template<class T> 
DynamicArray<T>::DynamicArray(int count) {
    array = new T[count];
    size = count;
}

template<class T> 
DynamicArray<T>::DynamicArray() {
    array = nullptr;
    size = 0;
}


template<class T> 
DynamicArray<T>::DynamicArray(DynamicArray<T>& const_array) {
    array = new T[const_array.getSize()];
    size = const_array.getSize();
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
void DynamicArray<T>::set(int index, T value) {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else
            array[index] = value;
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
            T* new_array = new T[newSize];

            for (int i(0); i < newSize; i++) {
                if (i < size)
                    new_array[i] = array[i];
            }
            array = new_array;
            size = newSize;
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