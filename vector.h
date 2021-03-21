#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
    int ReSize;
    int ImSize;
    void* ReArray;
    void* ImArray;
} vector;

vector* (*createRandomVector) (int* size);
vector* (*createVector) (int* size);

vector* (*sum) (vector* vector1, vector* vector2);
void (*scalarMultiply) (vector* vector1, vector* vector2);
vector* (*vectorMultiply) (vector* vector1, vector* vector2);
vector* (*numMultiply) (vector* vector1, vector* vector2);

#endif