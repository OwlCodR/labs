#include "menu.h"

#define INPUT_AUTO 0
#define INPUT_MANUALLY 1

#define TYPE_FLOAT 2
#define TYPE_COMPLEX 3

void throwError(const char* msg) {
    printf("\n");
    printf(msg);
    printf("\n");
    exit(0);
}

int getVectorType() {
    printf("\n=== Выберите область определения вектора ===   \n");
    printf("1. Вещественные числа \n");
    printf("2. Комплексные числа \n");

    int choice;
    printf("Мой выбор: ");
    scanf("%d", &choice);

    if (choice == 1) {
        return TYPE_FLOAT;
    } else if (choice == 2) {
        return TYPE_COMPLEX;
    } else {
        throwError("Ошибка! Некорректный ввод!");
        return -1;
    }
}

int getInputType() {
    printf("\n    === Выберите способ ввода вектора ===   \n");
    printf("1. Автоматически \n");
    printf("2. Вручную \n");

    int choice;
    printf("Мой выбор: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
        return INPUT_AUTO;
    } else if (choice == 2) {
        return INPUT_MANUALLY;
    } else {
        throwError("Ошибка! Некорректный ввод!");
        return -1;
    }
}

void printVectorFloat(Vector* vector) {
    printf("vector(%.3f, %.3f, %.3f)", *((float*) vector->x), *((float*) vector->y), *((float*) vector->z));
}

void printVectorComplex(Vector* vector) {
    printf("vector(%.3f + (%.3f)i, %.3f + (%.3f)i, %.3f + (%.3f)i)", 
        ((Complex*) vector->x)->Re, ((Complex*) vector->x)->Im, 
        ((Complex*) vector->y)->Re, ((Complex*) vector->y)->Im, 
        ((Complex*) vector->z)->Re, ((Complex*) vector->z)->Im);
}

void menu() {
    Vector* vector1 = (Vector*) malloc(sizeof(Vector));
    Vector* vector2 = (Vector*) malloc(sizeof(Vector));
    int choice = -1;

    while (choice != 4) {
        
        int inputType;
        int vectorType;
        
        printf("\n    === МЕНЮ ===    \n");
        printf(" >> 3-мерные векторы << \n");
        printf("1. Векторное сложение\n");
        printf("2. Скалярное произведение\n");
        printf("3. Векторное произведение\n");
        printf("4. Тесты\n");
        printf("5. Выход\n");

        printf("Мой выбор: ");
        
        scanf("%d", &choice);

        if (choice == 4) {
            tests();
            continue;
        } else if (choice == 5) {
            free(vector1);
            free(vector2);
            return;
        } else if (choice > 5 || choice < 1) {
            throwError("Ошибка! Некорректный ввод!");
            return;
        }
        else {
            vectorType = getVectorType();
            inputType = getInputType();
        }

        srand(time(NULL));

        if (vectorType == TYPE_FLOAT) 
        {
            if (inputType == INPUT_MANUALLY) 
            {
                printf("\n\n    === Ручной ввод ===   \n");
                printf("      vector(x, y, z)   \n");

                for (int i = 0; i < 2; i++) 
                {
                    float x, y, z;

                    printf("Вектор №%d:", i + 1);

                    printf("\nx:");
                    scanf("%f", &x);

                    printf("\ny:");
                    scanf("%f", &y);

                    printf("\nz:");
                    scanf("%f", &z);

                    if (!i)
                        vector1 = makeVectorFloat(x, y, z);
                    else
                        vector2 = makeVectorFloat(x, y, z);
                }
            } 

            if (inputType == INPUT_AUTO) 
            {
                for (int i = 0; i < 2; i++) 
                {
                    float x = rand() % 1000 / 100.0f - 5.0f;
                    float y = rand() % 1000 / 100.0f - 5.0f;
                    float z = rand() % 1000 / 100.0f - 5.0f;

                    if (!i)
                        vector1 = makeVectorFloat(x, y, z);
                    else
                        vector2 = makeVectorFloat(x, y, z);
                }
            }
        } 
        if (vectorType == TYPE_COMPLEX) 
        {
            if (inputType == INPUT_MANUALLY) {
                printf("\n\n    === Ручной ввод ===   \n");
                printf("  vector(x + xi, y + yi, z + zi)   \n");

                for (int i = 0; i < 2; i++) {
                    Complex* complex1 = (Complex*) malloc(sizeof(Complex));
                    Complex* complex2 = (Complex*) malloc(sizeof(Complex));
                    Complex* complex3 = (Complex*) malloc(sizeof(Complex));

                    printf("Вектор №%d:", i + 1);

                    printf("\nx:");
                    scanf("%f", &complex1->Re);

                    printf("\nxi:");
                    scanf("%f", &complex1->Im);

                    printf("\ny:");
                    scanf("%f", &complex2->Re);

                    printf("\nyi:");
                    scanf("%f", &complex2->Im);

                    printf("\nz:");
                    scanf("%f", &complex3->Re);

                    printf("\nzi:");
                    scanf("%f", &complex3->Im);

                    if (!i)
                        vector1 = makeVectorComplex(complex1, complex2, complex3);
                    else
                        vector2 = makeVectorComplex(complex1, complex2, complex3);
                }
            }
            
            if (inputType == INPUT_AUTO) {
                for (int i = 0; i < 2; i++) {
                    Complex* complex1 = (Complex*) malloc(sizeof(Complex));
                    Complex* complex2 = (Complex*) malloc(sizeof(Complex));
                    Complex* complex3 = (Complex*) malloc(sizeof(Complex));

                    complex1->Re = rand() % 1000 / 100.0 - 5.0f;
                    complex1->Im = rand() % 1000 / 100.0 - 5.0f;

                    complex2->Re = rand() % 1000 / 100.0 - 5.0f;
                    complex2->Im = rand() % 1000 / 100.0 - 5.0f;

                    complex3->Re = rand() % 1000 / 100.0 - 5.0f;
                    complex3->Im = rand() % 1000 / 100.0 - 5.0f;

                    if (!i)
                        vector1 = makeVectorComplex(complex1, complex2, complex3);
                    else
                        vector2 = makeVectorComplex(complex1, complex2, complex3);
                }
            }
        }

        switch(choice) {
            case 1:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("\n+\n");
                    printVectorFloat(vector2);
                    printf("\n=\n");
                    printVectorFloat(sumVectors(vector1, vector2));
                }

                if (vectorType == TYPE_COMPLEX) {
                    printVectorComplex(vector1);
                    printf("\n+\n");
                    printVectorComplex(vector2);
                    printf("\n=\n");
                    printVectorComplex(sumVectors(vector1, vector2));
                }
                break;
            }
            case 2:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("\n*\n");
                    printVectorFloat(vector2);
                    printf("\n=\n");

                    printf("%.3f\n", *((float*) scalarMultiply(vector1, vector2)));
                }

                if (vectorType == TYPE_COMPLEX) {
                    Complex* scalar = (Complex*) scalarMultiply(vector1, vector2);

                    printVectorComplex(vector1);
                    printf("\n*\n");
                    printVectorComplex(vector2);
                    printf("\n=\n");

                    printf("%.3f + (%.3f)i\n", scalar->Re, scalar->Im);
                }
                break;
            }
            case 3:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("\nx\n");
                    printVectorFloat(vector2);
                    printf("\n=\n");
                    printVectorFloat(vectorMultiply(vector1, vector2));
                }

                if (vectorType == TYPE_COMPLEX) {
                    printVectorComplex(vector1);
                    printf("\nx\n");
                    printVectorComplex(vector2);
                    printf("\n=\n");
                    printVectorComplex(vectorMultiply(vector1, vector2));
                }
                break;
            }
        }
    }

    free(vector1);
    free(vector2);
}