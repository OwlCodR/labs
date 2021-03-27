#include "complex.h"
#include "tests.h"

void testScalarFloat(float* answer, float number) {
    if (abs(*answer - number) < 0.001) {
        printf("\n============ TEST DONE ============\n");
        printf("%f\n", *answer);
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printf("%f", *answer);
        printf("\nCorrect: ");
        printf("%f\n", number);
    }
}

void testScalarComplex(Complex* answer, float Re, float Im) {    
    if (abs(answer->Re - Re) < 0.001 && (answer->Im - Im) < 0.001) {
        printf("\n============ TEST DONE ============\n");
        printf("%f + (%f)i\n", answer->Re, answer->Im);
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printf("%f + (%f)i", answer->Re, answer->Im);
        printf("\nCorrect: ");
        printf("%f + (%f)i\n", Re, Im);
    }
}


void testVectorsFloat(Vector* vector, float x, float y, float z) {
    if (abs(*((float*) vector->x) - x) < 0.001 &&
        abs(*((float*) vector->y) - y) < 0.001 &&
        abs(*((float*) vector->z) - z) < 0.001) {
        printf("\n============ TEST DONE ============\n");
        printVectorFloat(vector);
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printVectorFloat(vector);
        printf("\nCorrect: ");
        printVectorFloat(makeVectorFloat(x, y, z));
    }
}


void testVectorsComplex(Vector* vector, float ReX, float ImX, float ReY, float ImY, float ReZ, float ImZ) {
    if (abs(((Complex*) vector->x)->Re - ReX) < 0.001 && abs(((Complex*) vector->x)->Im - ImX) < 0.001 && 
        abs(((Complex*) vector->y)->Re - ReY) < 0.001 && abs(((Complex*) vector->y)->Im - ImY) < 0.001 &&
        abs(((Complex*) vector->z)->Re - ReZ) < 0.001 && abs(((Complex*) vector->z)->Im - ImZ) < 0.001) {
        printf("\n============ TEST DONE ============\n");
        printVectorComplex(vector);
    } else {
        printf("\n============ TEST FAILED !!! ============\n");
        printf("\nIncorrect: ");
        printVectorComplex(vector);
        printf("\nCorrect: ");
        printVectorComplex(makeVectorComplexFromFloats(ReX, ImX, ReY, ImY, ReZ, ImZ));
    }
}


void tests() {
    printf("\nTesting...");


    printf("\n      --- Vectors sum ---      \n");
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(1.1f, 1.1f, 1.1f), 
            makeVectorFloat(2.2f, 2.2f, 2.2f)), 
                            3.3f, 3.3f, 3.3f);
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(0.0f, 0.0f, 0.0f), 
            makeVectorFloat(-1000.1f, 1000.0f, 0.0f)), 
                            -1000.1f, 1000.0f, 0.0f);
    testVectorsFloat(
        sumVectors(
            makeVectorFloat(-10.0f, -7.0f, 0.0f), 
            makeVectorFloat(1.2f, 10.0f, -5.0f)), 
                            -8.8f, 3.0f, -5.0f);

    testVectorsComplex(
        sumVectors(
            makeVectorComplexFromFloats(1000.0f, 0.0f, -12.9f, 5.0f, -200.0, 4.2f), 
            makeVectorComplexFromFloats(0.0f, -500.0f, 12.9f, -10.0f, 300.0f, -5.2f)), 
                                        1000.0f, -500.0f, 0.0f, -5.0f, 100.0f, -1.0f);

    printf("\n      --- Scalar vectors multiply ---      \n");

    testScalarFloat(
        (float*) scalarMultiply(
            makeVectorFloat(10.0f, 54.9f, 0.0f), 
            makeVectorFloat(-5.0f, 1.0f, -34.4f)), 4.9f);

    testScalarComplex(
        (Complex*) scalarMultiply(
            makeVectorComplexFromFloats(10.0f, 0.0f, -12.9f, 5.0f, -20.0f, 4.2f), 
            makeVectorComplexFromFloats(0.0f, -50.0f, 12.9f, -10.0f, 30.0f, -5.2f)), -694.57f, -76.5f);
    
    printf("\n\n      --- Vector vectors multiply ---      \n");
    
    testVectorsFloat(
        vectorMultiply(
            makeVectorFloat(-10.0f, -7.0f, 0.0f), 
            makeVectorFloat(1.2f, 10.0f, -5.0f)), 
                            35.0f, -50.0f, -91.6f);

    testVectorsComplex(
        vectorMultiply(
            makeVectorComplexFromFloats(10.0f, 0.0f, -12.9f, 5.0f, -20.0f, 4.2f), 
            makeVectorComplexFromFloats(0.0f, -50.0f, 12.9f, -10.0f, 30.0f, -5.2f)), 
                                        -145.0f, 62.9f, -90.0f, -948.0f, -121.0f, 545.0f);
}