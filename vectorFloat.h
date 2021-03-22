#ifndef VECTORFLOAT_H
#define VECTORFLOAT_H

#include "vector.h"

// public
Vector* makeVectorFloat(float x, float y, float z);

// private
Vector* sumVectorsFloat(Vector* vector1, Vector* vector2);
float   scalarMultiplyFloat(Vector* vector1, Vector* vector2);
Vector* vectorMultiplyFloat(Vector* vector1, Vector* vector2);

#endif