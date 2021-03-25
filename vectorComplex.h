#ifndef VECTORCOMPLEX_H
#define VECTORCOMPLEX_H

#include "vector.h"
#include <string.h>

typedef struct Complex {
    float Re;
    float Im;
} Complex;

// public
Vector* makeVectorComplex(Complex* x, Complex* y, Complex* z);

// private
Vector* sumVectorsComplex(Vector* vector1, Vector* vector2);
void* scalarMultiplyComplex(Vector* vector1, Vector* vector2);
Vector* vectorMultiplyComplex(Vector* vector1, Vector* vector2);

Complex* sumComplex(Complex* complex1, Complex* complex2);
Complex* multiplyComplex(Complex* complex1, Complex* complex2);
Complex* inverseComplex(Complex* complex1);

#endif