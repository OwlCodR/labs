#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "vectorFloat.h"
#include "vectorComplex.h"
#include "tests.h"

void printMenu();
int getVectorType();
int getInputType();
void printVectorFloat(Vector* vector);
void printVectorComplex(Vector* vector);
void input(int vectorType, int inputType, Vector* vector1, Vector* vector2);

#endif