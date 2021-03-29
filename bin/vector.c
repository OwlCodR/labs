#include "vector.h"

Vector* makeVector(size_t sizeElement, Vector* (*sum)(Vector*, Vector*), void* (*scalar)(Vector*, Vector*), Vector* (*vecMultiply)(Vector*, Vector*), void* x, void* y, void* z) {
    Vector* new_vector = (Vector*) malloc(sizeof(Vector));
    
    new_vector->sizeElement = sizeElement;
    new_vector->sum = sum;
    new_vector->scalar = scalar;
    new_vector->vecMultiply = vecMultiply;

    new_vector->x = malloc(sizeElement);
    new_vector->y = malloc(sizeElement);
    new_vector->z = malloc(sizeElement);

    new_vector->x = x;
    new_vector->y = y;
    new_vector->z = z;

    return new_vector;
}

Vector* sumVectors(Vector* vector1, Vector* vector2) {
    return vector1->sum(vector1, vector2);
}

void* scalarMultiply(Vector* vector1, Vector* vector2) {
    return vector1->scalar(vector1, vector2);
}

Vector* vectorMultiply(Vector* vector1, Vector* vector2) {
    return vector1->vecMultiply(vector1, vector2);
}