#ifndef VECTORFLOAT_H
#define VECTORFLOAT_H

#include "vector.h"

typedef struct Complex {
    float Re;
    float Im;
} Complex;

// public
Vector* makeVectorComplex(Complex x, Complex y, Complex z);

// private
Vector* sumVectorsComplex(Vector* vector1, Vector* vector2);
float   scalarMultiplyComplex(Vector* vector1, Vector* vector2);
Vector* vectorMultiplyComplex(Vector* vector1, Vector* vector2);

#endif