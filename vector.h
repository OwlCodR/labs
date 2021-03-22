#ifndef VECTOR_H
#define VECTOR_H

#include <string.h>

typedef struct vector {
    size_t sizeElement;
    // Coordinates - float
    // Coordinates - float[2] (Re, Im)
    void* x;
    void* y;
    void* z;

    vector* (*sum)(vector*);
    void*   (*scalarMultiply)(vector*);
    vector* (*vectorMultiply)(vector*);
} vector;

vector* makeVector(size_t sizeElement, vector* (*sum), void* (*scalarMultiply), vector* (*vectorMultiply), void* x, void* y, void* z);

vector* sum(vector* vector1, vector* vector2);
void*   scalarMultiply(vector* vector1, vector* vector2);
vector* vectorMultiply(vector* vector1, vector* vector2);

#endif