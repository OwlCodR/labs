#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include "../Sequence/Sequence.h"
#include "../ArraySequence/ArraySequence.h"

using namespace std;

template<class T>
class Matrix {
public:
    Matrix();
    Matrix(int size);
    Matrix(int size, T** data);
    Matrix(Sequence<Sequence<T>> &mat);
    Matrix(Matrix<T> &mat);

    void getSize();
    void makeZero();
    void set(int i, int j, T value);
    void print(bool debug);
    T getNorm();

    Matrix<T> transpose();
    
    Matrix<T> multiplyColumnBy(int column, T number);
    Matrix<T> sumColumn(int column1, int column1);
    Matrix<T> sumMultipliedColumn(int column1, int column1, T number);
    Matrix<T> swapColumns(int column1, int column1);

    Matrix<T> multiplyRowBy(int row, T number);
    Matrix<T> sumRow(int row1, int row2);
    Matrix<T> sumMultipliedRow(int row1, int row2, T number);
    Matrix<T> swapRows(int row1, int row2);

    Matrix<T> operator*(Matrix<T> mat);
    Matrix<T> operator*(T number);
    Matrix<T> operator+(Matrix<T> mat);
    Matrix<T> operator-(Matrix<T>& mat);
    Matrix<T>& operator=(Matrix<T>& mat);
    ArraySequence<T>& operator[](int index);

private:
    int size;
    ArraySequence<ArraySequence<T>> matrix;
};

#endif