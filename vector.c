#include "vector.h"

Vector* makeVector(size_t sizeElement, Vector* (*sum), void* (*scalarMultiply), Vector* (*vectorMultiply), void* x, void* y, void* z) {
    Vector* newVector = malloc(sizeof(Vector));
    
    newVector->sizeElement = sizeElement;
    newVector->sum = sum;
    newVector->scalarMultiply = scalarMultiply;
    newVector->vectorMultiply = vectorMultiply;

    newVector->x = malloc(sizeElement);
    newVector->y = malloc(sizeElement);
    newVector->z = malloc(sizeElement);

    newVector->x = x;
    newVector->y = y;
    newVector->z = z;

    return newVector;
}

Vector* sumVectors(Vector* vector1, Vector* vector2) {
    return vector1->sum(vector2);
}

void* scalarMultiply(Vector* vector1, Vector* vector2) {
    return vector1->scalarMultiply(vector2);
}

Vector* vectorMultiply(Vector* vector1, Vector* vector2) {
    return vector1->vectorMultiply(vector2);
}