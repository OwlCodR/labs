#include "complex.h"
#include "tests.h"

void testScalarFloat(float* answer, float number) {
    if (*answer == number) {
        printf("\n============ TEST DONE ============\n");
        printf("%f", *answer);
        printf("\n============ TEST DONE ============\n");
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printf("%f", *answer);
        printf("\nCorrect: ");
        printf("%f", number);
        printf("\n============ TEST FAILED !!! ============\n");
    }
}

void testScalarComplex(Complex* answer, float Re, float Im) {    
    if (answer->Re == Re && answer->Im == Im) {
        printf("\n============ TEST DONE ============\n");
        printf("%f + (%f)i", answer->Re, answer->Im);
        printf("\n============ TEST DONE ============\n");
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printf("%f + (%f)i", answer->Re, answer->Im);
        printf("\nCorrect: ");
        printf("%f + (%f)i", Re, Im);
        printf("\n============ TEST FAILED !!! ============\n");
    }
}


void testVectorsFloat(Vector* vector, float x, float y, float z) {
    if (*((float*) vector->x) == x &&
        *((float*) vector->y) == y &&
        *((float*) vector->z) == z) {
        printf("\n============ TEST DONE ============\n");
        printVectorFloat(vector);
        printf("\n============ TEST DONE ============\n");
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printVectorFloat(vector);
        printf("\nCorrect: ");
        printVectorFloat(makeVectorFloat(x, y, z));
        printf("\n============ TEST FAILED !!! ============\n");
    }
}

void testVectorsComplex(Vector* vector, float ReX, float ImX, float ReY, float ImY, float ReZ, float ImZ) {
    if (((Complex*) vector->x)->Re == ReX && ((Complex*) vector->x)->Im == ImX && 
        ((Complex*) vector->y)->Re == ReY && ((Complex*) vector->y)->Im == ImY &&
        ((Complex*) vector->z)->Re == ReZ && ((Complex*) vector->z)->Im == ImZ) {
        printf("\n============ TEST DONE ============\n");
        printVectorComplex(vector);
        printf("\n============ TEST DONE ============\n");
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printVectorComplex(vector);
        printf("\nCorrect: ");
        printVectorComplex(makeVectorComplexFromFloats(ReX, ImX, ReY, ImY, ReZ, ImZ));
        printf("\n============ TEST FAILED !!! ============\n");
    }
}

void tests() {
    printf("\nTesting...");


    printf("\n      --- Vectors sum ---      \n");
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(1.1, 1.1, 1.1), 
            makeVectorFloat(2.2, 2.2, 2.2)), 
                            3.3, 3.3, 3.3);
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(0.0, 0.0, 0.0), 
            makeVectorFloat(-1000.1, 1000.0, 0.0)), 
                            -1000.1, 1000.0, 0.0);
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(-10.0, -7.0, 0.0), 
            makeVectorFloat(1.2, 10.0, -5.0)), 
                            8.8, 3.0, -5.0);

    testVectorsComplex(
        sumVectors(
            makeVectorComplexFromFloats(1000.0, 0.0, -12.9, 5.0, -200.0, 4.2), 
            makeVectorComplexFromFloats(0.0, -500.0, 12.9, -10.0, 300.0, -5.2)), 
                                        1000.0, -500.0, 0.0, -5.0, 100.0, -1.0);

    printf("\n      --- Scalar vectors multiply ---      \n");

    testScalarFloat(
        (float*) scalarMultiply(
            makeVectorFloat(10.0, 54.9, 0.0), 
            makeVectorFloat(-5.0, 1.0, -34.4)), 4.9);

    testScalarComplex(
        (Complex*) scalarMultiply(
            makeVectorComplexFromFloats(10.0, 0.0, -12.9, 5.0, -20.0, 4.2), 
            makeVectorComplexFromFloats(0.0, -50.0, 12.9, -10.0, 30.0, -5.2)), -694.57, -76.5);
    
    printf("\n      --- Vector vectors multiply ---      \n");
    
    testVectorsFloat(
        vectorMultiply(
            makeVectorFloat(-10.0, -7.0, 0.0), 
            makeVectorFloat(1.2, 10.0, -5.0)), 
                            35.0, -50.0, -91.6);

    testVectorsComplex(
        vectorMultiply(
            makeVectorComplexFromFloats(10.0, 0.0, -12.9, 5.0, -20.0, 4.2), 
            makeVectorComplexFromFloats(0.0, -50.0, 12.9, -10.0, 30.0, -5.2)), 
                                        0.0, -50.0, 12.9, -10.0, 30.0, -5.2);
}