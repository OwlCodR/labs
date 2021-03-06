#ifndef VECTOR_H
#define VECTOR_H

#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Vector {
    size_t sizeElement;
    void* x;
    void* y;
    void* z;

    Vector* (*sum)(Vector*, Vector*);
    void*   (*scalar)(Vector*, Vector*);
    Vector* (*vecMultiply)(Vector*, Vector*);
} Vector;

// private
Vector* makeVector(size_t sizeElement, Vector* (*sum)(Vector*, Vector*), void* (*scalar)(Vector*, Vector*), Vector* (*vecMultiply)(Vector*, Vector*), void* x, void* y, void* z);

// public
Vector* sumVectors(Vector* vector1, Vector* vector2);
// public
void*   scalarMultiply(Vector* vector1, Vector* vector2);
// public
Vector* vectorMultiply(Vector* vector1, Vector* vector2);

#endif