#include "vector.h"

vector* makeVector(size_t sizeElement, vector* (*sum), void* (*scalarMultiply), vector* (*vectorMultiply), void* x, void* y, void* z) {
    vector* newVector = malloc(sizeof(vector));
    
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

vector* sum(vector* vector1, vector* vector2) {
    return vector1->sum(vector2);
}

void* scalarMultiply(vector* vector1, vector* vector2) {
    return vector1->scalarMultiply(vector2);
}

vector* vectorMultiply(vector* vector1, vector* vector2) {
    return vector1->vectorMultiply(vector2);
}