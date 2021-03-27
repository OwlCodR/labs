#ifndef TESTS_H
#define TESTS_H

#include "vector.h"
#include "vectorFloat.h"
#include "vectorComplex.h"
#include "menu.h"
#include "cmath"


// public
void tests();

// private
void testVectorsFloat(Vector* vector, float x, float y, float z);
// private
void testVectorsComplex(Vector* vector, float ReX, float ImX, float ReY, float ImY, float ReZ, float ImZ);

#endif