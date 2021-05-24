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
    for (int i(0); i < size; i++) {
        array[i] = nullptr;
    }
}


template<class T> 
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) {
    array = new T[array.getSize()];
    for (int i(0); i < array.getSize(); i++) {
        this->array[i] = array[i];
        this->size++;
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
int DynamicArray<T>::getSize() {
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

            for (int i(0); i < newSize; i++) 
            {
                if (i < size) 
                    new_array[i] = array[i];
                else 
                    new_array[i] = 0;
            }
            size = newSize;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
    }
}

template<class T> 
T& DynamicArray<T>::operator[](const int index) {
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
void DynamicArray<T>::print(bool debug) {
    if (debug)
        cout << "DynamicArray[" << size << "]: ";
    for (int i(0); i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<class T> 
string DynamicArray<T>::to_string() {
    string s = "";

    for (int i(0); i < size; i++) {
        s += std::to_string(array[i]);
        if (i != size - 1)
            s += " ";
    }

    cout << "to_string() = " << s << endl;
    return s;
}