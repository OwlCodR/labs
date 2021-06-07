#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <string>
#include "../Sequence/Sequence.h"
#include "../ArraySequence/ArraySequence.h"

using namespace std;

template<class T>
class Matrix {
public:
    Matrix();
    Matrix(int size);
    Matrix(T** data, int size);
    Matrix(const ArraySequence<ArraySequence<T>> mat);
    Matrix(const Matrix<T>& mat);

    const DynamicArray<T> getDynamicArray();
    void set(int i, int j, T value);
    void print(bool isDebug);
    T get(int i, int j);
    string to_string();
    void makeZero();
    int getSize();
    int getSize() const;

    T getNorm();
    T getColumnsNorm();
    T getRowsNorm();

    Matrix<T> transpose();
    
    Matrix<T> multiplyColumnBy(int column, T number);
    Matrix<T> sumColumn(int column1, int column2);
    Matrix<T> sumMultipliedColumn(int column1, int column2, T number);
    Matrix<T> swapColumns(int column1, int column2);

    Matrix<T> multiplyRowBy(int row, T number);
    Matrix<T> sumRow(int row1, int row2);
    Matrix<T> sumMultipliedRow(int row1, int row2, T number);
    Matrix<T> swapRows(int row1, int row2);

    Matrix<T> operator*(Matrix<T> mat);
    Matrix<T> operator*(T number);
    Matrix<T> operator+(Matrix<T> mat);
    Matrix<T> operator-(Matrix<T>& mat);
    ArraySequence<T>& operator[](int index);
    ArraySequence<T> operator[](int index) const;

private:
    int size;
    ArraySequence<ArraySequence<T>> matrix;
};

#endif