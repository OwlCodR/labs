#include "vectorComplex.h"

Vector* makeVectorComplexFromFloats(float ReX, float ImX, float ReY, float ImY, float ReZ, float ImZ) {
    Complex* complex_x = (Complex*) malloc(sizeof(Complex));
    Complex* complex_y = (Complex*) malloc(sizeof(Complex));
    Complex* complex_z = (Complex*) malloc(sizeof(Complex));
    
    complex_x->Re = ReX; 
    complex_x->Im = ImX;
     
    complex_y->Re = ReY; 
    complex_y->Im = ImY;
        
    complex_z->Re = ReZ; 
    complex_z->Im = ImZ;

    return makeVector(sizeof(Complex), sumVectorsComplex, scalarMultiplyComplex, vectorMultiplyComplex, complex_x, complex_y, complex_z);
}

Vector* makeVectorComplex(Complex* x, Complex* y, Complex* z) {
    return makeVector(sizeof(Complex), sumVectorsComplex, scalarMultiplyComplex, vectorMultiplyComplex, x, y, z);
}

Vector* sumVectorsComplex(Vector* vector1, Vector* vector2) {
    Complex* sum_x = (Complex*) malloc(sizeof(Complex));
    Complex* sum_y = (Complex*) malloc(sizeof(Complex));
    Complex* sum_z = (Complex*) malloc(sizeof(Complex));

    sum_x = sumComplex((Complex*) vector1->x, (Complex*) vector2->x);
    sum_y = sumComplex((Complex*) vector1->y, (Complex*) vector2->y);
    sum_z = sumComplex((Complex*) vector1->z, (Complex*) vector2->z);

    return makeVector(sizeof(Complex), sumVectorsComplex, scalarMultiplyComplex, vectorMultiplyComplex, sum_x, sum_y, sum_z);
}

void* scalarMultiplyComplex(Vector* vector1, Vector* vector2) {

    /*
        a * b = x1 * x2 + y1 * y2 + z1 * z2
    */

    Complex* x1x2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->x);
    Complex* y1y2 = multiplyComplex((Complex*) vector1->y, (Complex*) vector2->y);
    Complex* z1z2 = multiplyComplex((Complex*) vector1->z, (Complex*) vector2->z);

    return (void*) sumComplex(x1x2, sumComplex(y1y2, z1z2));
}

Vector* vectorMultiplyComplex(Vector* vector1, Vector* vector2) {
    Complex* y1z2 = multiplyComplex((Complex*) vector1->y, (Complex*) vector2->z);
    Complex* x1z2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->z);
    Complex* x1y2 = multiplyComplex((Complex*) vector1->x, (Complex*) vector2->y);

    Complex* y2z1 = multiplyComplex((Complex*) vector2->y, (Complex*) vector1->z);
    Complex* x2z1 = multiplyComplex((Complex*) vector2->x, (Complex*) vector1->z);
    Complex* x2y1 = multiplyComplex((Complex*) vector2->x, (Complex*) vector1->y);

    Complex* new_x = sumComplex(y1z2, inverseComplex(y2z1));
    Complex* new_y = sumComplex(x2z1, inverseComplex(x1z2));
    Complex* new_z = sumComplex(x1y2, inverseComplex(x2y1));

    return makeVector(sizeof(Complex), sumVectorsComplex, scalarMultiplyComplex, vectorMultiplyComplex, new_x, new_y, new_z);
}

//////////////////////////////////////////////////////////////////

Complex* sumComplex(Complex* complex1, Complex* complex2) {

    /*
        (a1 + b1*i) + (a2 + b2*i) = (a1 + a2) + (b1 + b2)*i
    */

    Complex* sum_complex = (Complex*) malloc(sizeof(Complex));

    sum_complex->Re = complex1->Re + complex2->Re;
    sum_complex->Im = complex1->Im + complex2->Im;

    return sum_complex;
}

Complex* multiplyComplex(Complex* complex1, Complex* complex2) {

    /*
        (a1 + b1*i)(a2 + b2*i) = (a1a2 - b1b2) + (a1b2 - b1a2)*i
    */

    Complex* new_complex = (Complex*) malloc(sizeof(Complex));

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