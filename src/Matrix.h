#ifndef MATRIX_H
#define MATRIX_H

#include "Sequence.h"

using namespace std;

template<class T>
class Matrix {
public:
    Matrix();
    Matrix(int size, T* data);
    ~Matrix();

    void getSize();
    void generate();
    void set(int i, int j, T value);
    void print(bool debug);
    Matrix<T>& operator+(Matrix mat);
    Matrix<T>& operator-(Matrix mat);
private:
    int size;
    Sequence<Sequence<T>> matrix;
};

#endif