#ifndef VECTOR_H
#define VECTOR_H

#include <string.h>

typedef struct Vector {
    size_t sizeElement;
    // Coordinates - float
    // Coordinates - float[2] (Re, Im)
    void* x;
    void* y;
    void* z;

    Vector* (*sum)(Vector*);
    void*   (*scalarMultiply)(Vector*);
    Vector* (*vectorMultiply)(Vector*);
} Vector;

// private
Vector* makeVector(size_t sizeElement, Vector* (*sum), void* (*scalarMultiply), Vector* (*vectorMultiply), void* x, void* y, void* z);

// public
Vector* sumVectors(Vector* vector1, Vector* vector2);
void*   scalarMultiply(Vector* vector1, Vector* vector2);
Vector* vectorMultiply(Vector* vector1, Vector* vector2);

#endif