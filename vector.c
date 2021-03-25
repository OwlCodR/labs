#include "vector.h"

Vector* makeVector(size_t sizeElement, Vector* (*sum)(Vector*, Vector*), void* (*scalar)(Vector*, Vector*), Vector* (*vecMultiply)(Vector*, Vector*), void* x, void* y, void* z) {
    Vector* newVector = (Vector*) malloc(sizeof(Vector));
    
    newVector->sizeElement = sizeElement;
    newVector->sum = sum;
    newVector->scalar = scalar;
    newVector->vecMultiply = vecMultiply;

    newVector->x = malloc(sizeElement);
    newVector->y = malloc(sizeElement);
    newVector->z = malloc(sizeElement);

    newVector->x = x;
    newVector->y = y;
    newVector->z = z;

    return newVector;
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