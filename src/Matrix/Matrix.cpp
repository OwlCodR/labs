#include "Matrix.h"

template<class T>
Matrix<T>::Matrix() {
    size = 0;
    matrix = new ArraySequence<ArraySequence<T>>();
}
 
template<class T>
Matrix<T>::Matrix(int size) {
    this->size = size;
    matrix = new ArraySequence<ArraySequence<T>>();
    makeZero();
}
 
template<class T>
Matrix<T>::Matrix(int size, T** data) {
    this->size = size;
    matrix = new ArraySequence<ArraySequence<T>>(size, data); // ?
}

template<class T>
Matrix<T>::Matrix(Sequence<Sequence<T>> &mat) {
    this->size = mat.getSize();

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            this->matrix[i][j] = mat[i][j];
        }
    }
}

template<class T>
Matrix<T>::Matrix(Matrix<T> &mat) {
    this->size = mat.getSize();

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            this->matrix[i][j] = mat[i][j];
        }
    }
}
 
template<class T>
void Matrix<T>::getSize() {
    return this->size;
}

template<class T>
void Matrix<T>::makeZero() {
    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            matrix[i][j] = 0;
        }
    }
}

template<class T>
void Matrix<T>::set(int i, int j, T value) {
    matrix[i][j] = value;
    // add try-catch
}

template<class T>
void Matrix<T>::print(bool debug) {
    if (debug)
        cout << "Matrix[" << getSize() << "]:" << endl;

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


template<class T>
T Matrix<T>::getNorm() {
    T sum = 0;
    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            sum += pow(matrix[i][j], 2);
        }
    }
    return sqrt(sum);
}


/*! @brief Multiplies every matrix element by number.
 *
 *  @param[in] number The number to multiply
 *
 */
template<class T>
Matrix<T> Matrix<T>::multiplyBy(T number) {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            new_mat[i][j] = new_mat[i][j] * number;
        }
    }

    return new_mat;
}


/*! @brief Multiplies Matrix by another Matrix.
 *
 *  @param[in] mat The Matrix to multiply
 *
 */
template<class T>
Matrix<T> Matrix<T>::multiplyBy(Matrix<T>& mat) {
    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            //
        }
    }
}


//! @brief Replaces rows with columns.
template<class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            T temp = new_mat[i][j];
            new_mat[i][j] = new_mat[j][i];
            new_mat[j][i] = new_mat;
        }
    }

    return new_mat;
}

///////////////////////////////////////////////////////////

/*! @brief Multiplies column by number.
 *
 *  @param[in] column The index of column
 *  @param[in] number The number to multiply
 */
template<class T>  // != 0
Matrix<T> Matrix<T>::multiplyColumnBy(int column, T number) {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        new_mat[i][column] = new_mat[i][column] * number;
    }
    
    return new_mat;
}


/*! @brief Adds column to another.
 *
 *  @param[in] column1 The index of column to add
 *  @param[in] column2 The index of column which add to the first column
 */
template<class T>
Matrix<T> Matrix<T>::sumColumn(int column1, int column2) {
    Matrix<T> new_mat(this->matrix);
    
    for (int i(0); i < getSize(); i++) {
        new_mat[i][column1] += new_mat[i][column2];
    }
    
    return new_mat;
}


/*! @brief Adds multiplied column to another.
 *
 *  @param[in] column1 The index of column to add
 *  @param[in] column2 The index of multiplied by number column which add to the first column
 *  @param[in] number The number to multiply column2 by
 */
template<class T>
Matrix<T> Matrix<T>::sumMultipliedColumn(int column1, int column2, T number) {
    Matrix<T> new_mat(this->matrix);
    
    for (int i(0); i < getSize(); i++) {
        new_mat[i][column1] += new_mat[i][column2] * number;
    }
    
    return new_mat;
}


/*! @brief Swaps columns.
 *
 *  @param[in] column1 The index of first column to swap
 *  @param[in] column2 The index of second column to swap
 */
template<class T>
Matrix<T> Matrix<T>::swapColumns(int column1, int column2) {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        T temp = new_mat[i][column1];
        new_mat[i][column1] = new_mat[i][column2];
        new_mat[i][column2] = temp;
    }
    
    return new_mat;
}

//////////////////////////////////////////////////////////////////


/*! @brief Multiplies row by number.
 *
 *  @param[in] column The index of row
 *  @param[in] number The number to multiply
 */
template<class T> // != 0
Matrix<T> Matrix<T>::multiplyRowBy(int row, T number) {
    Matrix<T> new_mat(this->matrix);

    for (int j(0); j < getSize(); j++) {
        new_mat[row][j] = new_mat[row][j] * number;
    }
    
    return new_mat;
}

/*! @brief Adds row to another.
 *
 *  @param[in] column1 The index of row to add
 *  @param[in] column2 The index of row which add to the first row
 */
template<class T>
Matrix<T> Matrix<T>::sumRow(int row1, int row2) {
    Matrix<T> new_mat(this->matrix);

    for (int j(0); j < getSize(); j++) {
        new_mat[row1][j] += new_mat[row2][j];
    }
    
    return new_mat;
}


/*! @brief Adds multiplied row to another.
 *
 *  @param[in] row1 The index of row to add
 *  @param[in] row2 The index of multiplied by number row which add to the first row
 *  @param[in] number The number to multiply row2 by
 */
template<class T>
Matrix<T> Matrix<T>::sumMultipliedRow(int row1, int row2, T number) {
    Matrix<T> new_mat(this->matrix);

    for (int j(0); j < getSize(); j++) {
        new_mat[row1][j] += new_mat[row2][j] * number;;
    }
    
    return new_mat;
}


/*! @brief Swaps rows.
 *
 *  @param[in] row1 The index of first row to swap
 *  @param[in] row2 The index of second row to swap
 */
template<class T>
Matrix<T> Matrix<T>::swapRows(int row1, int row2) {
    Matrix<T> new_mat(this->matrix);

    ArraySequence<T> temp = new_mat[row1];
    new_mat[row1] = new_mat[row2];
    new_mat[row2] = temp;
    
    return new_mat;
}

///////////////////////////////////////////////////////////

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix& mat) {
    // Add check size
    Matrix<T> multiplied(this->matrix);

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            T sum = 0;
            for (int k(0); k < getSize(); k++) {
                sum += multiplied[i][k] * multiplied[k][j];
            }
            multiplied[i][j] = sum;
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix& mat) {
    Matrix<T> sum(this->matrix);
    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            sum[i][j] += mat[i][j];
        }
    }
    return sum;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix& mat) {
    Matrix<T> delta(this->matrix);
    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            delta[i][j] -= mat[i][j];
        }
    }
    return delta;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix& mat) {
    if (this == &mat)
        return this;
    
    this->size = mat.getSize();

    for (int i(0); i < getSize(); i++) {
        for (int j(0); i < getSize(); i++) {
            this->matrix[i][j] = mat[i][j];
        }
    }
    return this;
}

template<class T>
ArraySequence<T>& Matrix<T>::operator[](int index) {
    return this->matrix[index];
}