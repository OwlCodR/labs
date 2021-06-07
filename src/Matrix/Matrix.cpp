#include "Matrix.h"

template<class T>
Matrix<T>::Matrix() {
    size = 0;
    matrix = ArraySequence<ArraySequence<T>>();
}
 
template<class T>
Matrix<T>::Matrix(int size) {
    this->size = size;
    matrix = ArraySequence<ArraySequence<T>>();
    makeZero();
}
 
template<class T>
Matrix<T>::Matrix(T** data, int size) {
    this->size = size;
    ArraySequence<ArraySequence<T>> mat = ArraySequence<ArraySequence<T>>();
    for (int i(0); i < size; i++) {
        ArraySequence<T> sequence(data[i], size);
        mat.append(sequence);
    }

    this->matrix = mat;
}

template<class T>
Matrix<T>::Matrix(const ArraySequence<ArraySequence<T>> mat) {
    this->size = mat.getSize();

    ArraySequence<ArraySequence<T>> arraySequences = ArraySequence<ArraySequence<T>>();
    for (int i(0); i < size; i++) {
        ArraySequence<T> sequence = ArraySequence<T>();
        for (int j(0); j < size; j++) {
            sequence.append(mat[i][j]);
        }
        arraySequences.append(sequence);
    }

    this->matrix = arraySequences;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& mat) {
    this->size = mat.getSize();

    ArraySequence<ArraySequence<T>> arraySequences = ArraySequence<ArraySequence<T>>();
    for (int i(0); i < size; i++) {
        ArraySequence<T> sequence = ArraySequence<T>();
        for (int j(0); j < size; j++) {
            sequence.append(mat[i][j]);
        }
        arraySequences.append(sequence);
    }

    this->matrix = arraySequences;
}
 
template<class T>
int Matrix<T>::getSize() {
    return this->size;
}

template<class T>
int Matrix<T>::getSize() const {
    return this->size;
}

template<class T>
void Matrix<T>::makeZero() {
    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            matrix[i][j] = 0;
        }
    }
}

template<class T>
void Matrix<T>::set(int i, int j, T value) {
    try
    {
        if (i < 0 || i > getSize() || j < 0 || j > getSize())
            throw "IndexOutOfRange";
        else {
            matrix[i][j] = value;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T>
T Matrix<T>::get(int i, int j) {
    try
    {
        if (i < 0 || i > getSize() || j < 0 || j > getSize())
            throw "IndexOutOfRange";
        else {
            return matrix[i][j];
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T>
void Matrix<T>::print(bool isDebug) {
    if (isDebug)
        cout << "Matrix[" << getSize() << "]:" << endl;

    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//! @brief Returns sqrt of sum of squares of elements
template<class T>
T Matrix<T>::getNorm() {
    T sum = 0;
    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            sum += pow(matrix[i][j], 2);
        }
    }
    return sqrt(sum);
}


//! @brief Returns the max sum of elements in rows
template<class T>
T Matrix<T>::getRowsNorm() {
    if (getSize() == 0)
        return 0;

    T sum = matrix[0][0];
    for (int i(0); i < getSize(); i++) {
        T row_sum = matrix[i][0];
        for (int j(1); j < getSize(); j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum > sum) {
            sum = row_sum;
        }
    }
    return sum;
}

//! @brief Returns the max sum of elements in columns
template<class T>
T Matrix<T>::getColumnsNorm() {
    if (getSize() == 0)
        return 0;

    T sum = matrix[0][0];
    for (int i(0); i < getSize(); i++) {
        T column_sum = matrix[0][i];
        for (int j(1); j < getSize(); j++) {
            column_sum += matrix[j][i];
        }
        if (column_sum > sum) {
            sum = column_sum;
        }
    }
    return sum;
}


//! @brief Replaces rows with columns.
template<class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            if (j > i) {
                T temp = new_mat[i][j];
                new_mat[i][j] = new_mat[j][i];
                new_mat[j][i] = temp;
            }
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
    if (number == 0) {
        cerr << "Multiply by Zero" << endl;
        exit(0);
    }

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
    Matrix<T> new_mat(matrix);
    
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
    if (number == 0) {
        cerr << "Multiply by Zero" << endl;
        exit(0);
    }

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
Matrix<T> Matrix<T>::operator*(T number) {
    Matrix<T> new_mat(this->matrix);

    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            new_mat[i][j] = new_mat[i][j] * number;
        }
    }

    return new_mat;
}


template<class T>
Matrix<T> Matrix<T>::operator*(Matrix mat) {
    Matrix<T> new_mat(this->matrix);

    if (getSize() != mat.getSize()) {
        cerr << "Different size of matrixes" << endl;
        exit(0);
    }

    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            T sum = 0;
            for (int k(0); k < getSize(); k++) {
                sum += this->matrix[i][k] * mat[k][j];
            }
            new_mat[i][j] = sum;
        }
    }

    return new_mat;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix mat) {
    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            mat[i][j] += this->matrix[i][j];
        }
    }
    return mat;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix& mat) {
    Matrix<T> delta(this->matrix);
    for (int i(0); i < getSize(); i++) {
        for (int j(0); j < getSize(); j++) {
            delta[i][j] -= mat[i][j];
        }
    }
    return delta;
}

template<class T>
ArraySequence<T>& Matrix<T>::operator[](int index) {
    return this->matrix[index];
}

template<class T>
ArraySequence<T> Matrix<T>::operator[](int index) const {
    return this->matrix[index];
}