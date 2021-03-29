#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "vectorFloat.h"
#include "vectorComplex.h"
#include "tests.h"

void menu();
int getVectorType();
int getInputType();
void printVectorFloat(Vector* vector);
void printVectorComplex(Vector* vector);

#endif