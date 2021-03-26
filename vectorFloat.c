#include "vectorFloat.h"

Vector* makeVectorFloat(float x1, float y1, float z1) {
    float* x = (float*) malloc(sizeof(float));
    float* y = (float*) malloc(sizeof(float));
    float* z = (float*) malloc(sizeof(float));

    *x = x1;
    *y = y1;
    *z = z1;

    return makeVector(sizeof(float), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, x, y, z);
}

Vector* sumVectorsFloat(Vector* vector1, Vector* vector2) {
    
    float* new_x = (float*) malloc(sizeof(float));
    float* new_y = (float*) malloc(sizeof(float));
    float* new_z = (float*) malloc(sizeof(float));

    *new_x = *((float*) vector1->x) + *((float*) vector2->x);
    *new_y = *((float*) vector1->y) + *((float*) vector2->y);
    *new_z = *((float*) vector1->z) + *((float*) vector2->z);

    /*
        1. Преобразовать void* в float*
        2. Разыменовать float*
        3. Сложить два float
    */

    return makeVector(sizeof(float), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, new_x, new_y, new_z);
}

void* scalarMultiplyFloat(Vector* vector1, Vector* vector2) {
    float x1 = *((float*) vector1->x);
    float x2 = *((float*) vector2->x);

    float y1 = *((float*) vector1->y);
    float y2 = *((float*) vector2->y);

    float z1 = *((float*) vector1->z);
    float z2 = *((float*) vector2->z);

    float* sum = (float*) malloc(sizeof(float));
    *sum = x1*x2 + y1*y2 + z1*z2;

    return (void*) sum;
}

Vector* vectorMultiplyFloat(Vector* vector1, Vector* vector2) {
    float x1 = *((float*) vector1->x);
    float x2 = *((float*) vector2->x);

    float y1 = *((float*) vector1->y);
    float y2 = *((float*) vector2->y);

    float z1 = *((float*) vector1->z);
    float z2 = *((float*) vector2->z);

    float* new_x = (float*) malloc(sizeof(float));
    float* new_y = (float*) malloc(sizeof(float));
    float* new_z = (float*) malloc(sizeof(float));

    *new_x = y1*z2 - y2*z1;
    *new_y = x1*z2 - x2*z1;
    *new_z = x1*y2 - x2*y1;

    return makeVector(sizeof(float), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, new_x, new_y, new_z);
}