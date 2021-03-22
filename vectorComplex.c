#include "vectorComplex.h"

Vector* makeVectorFloat(Complex* x, Complex* y, Complex* z) {
    return makeVector(sizeof(Complex), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, x, y, z);
}

Vector* sumVectorsFloat(Vector* vector1, Vector* vector2) {
    Complex* new_x = malloc(sizeof(Complex));
    Complex* new_y = malloc(sizeof(Complex));
    Complex* new_z = malloc(sizeof(Complex));

    new_x = sumComplex((Complex*) vector1->x, (Complex*) vector2->x);
    new_y = sumComplex((Complex*) vector1->y, (Complex*) vector2->y);
    new_z = sumComplex((Complex*) vector1->z, (Complex*) vector2->z);

    return makeVector(sizeof(float), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, new_x, new_y, new_z);
}

Complex scalarMultiplyFloat(Vector* vector1, Vector* vector2) {

    /*
        a * b = ax * bx + ay * by
    */

    Complex* x1x2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->x);
    Complex* y1y2 = multiplyComplex((Complex*) vector1->y, (Complex*) vector2->y);
    Complex* z1z2 = multiplyComplex((Complex*) vector1->z, (Complex*) vector2->z);

    return *sumComplex(x1x2, sumComplex(y1y2, z1z2));
}

Vector* vectorMultiplyFloat(Vector* vector1, Vector* vector2) {
    Complex* y1z2 = multiplyComplex((Complex*) vector1->y, (Complex*) vector2->z);
    Complex* x1z2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->z);
    Complex* x1y2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->y);

    Complex* y2z1 = multiplyComplex((Complex*) vector2->y, (Complex*) vector1->z);
    Complex* x2z1 = multiplyComplex((Complex*) vector2->x, (Complex*) vector1->z);
    Complex* x2y1 = multiplyComplex((Complex*) vector2->x, (Complex*) vector1->y);

    Complex* new_x = sumComplex(y1z2, inverseComplex(y2z1));
    Complex* new_y = sumComplex(x1z2, inverseComplex(x2z1));
    Complex* new_z = sumComplex(x1y2, inverseComplex(x2y1));

    return makeVector(sizeof(float), sumVectorsFloat, scalarMultiplyFloat, vectorMultiplyFloat, new_x, new_y, new_z);
}

//////////////////////////////////////////////////////////////////

Complex* sumComplex(Complex* complex1, Complex* complex2) {

    /*
        (a1 + b1*i) + (a2 + b2*i) = (a1 + a2) + (b1 + b2)*i
    */

    Complex* new_complex = malloc(sizeof(Complex));

    new_complex->Re = complex1->Re + complex2->Re;
    new_complex->Im = complex1->Im + complex2->Im;

    return new_complex;
}

Complex* multiplyComplex(Complex* complex1, Complex* complex2) {

    /*
        (a1 + b1*i)(a2 + b2*i) = (a1a2 - b1b2) + (a1b2 - b1a2)*i
    */

    Complex* new_complex = malloc(sizeof(Complex));

    new_complex->Re = (complex1->Re * complex2->Re) - (complex1->Im * complex2->Im);
    new_complex->Im = (complex1->Re * complex2->Im) - (complex1->Im * complex2->Re);

    return new_complex;
}

Complex* inverseComplex(Complex* complex) {
    complex->Re = - complex->Re;
    complex->Im = - complex->Im;

    return complex;
    
    // Not sure
}