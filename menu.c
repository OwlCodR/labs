#include "menu.h"

#define INPUT_AUTO 0
#define INPUT_MANUALLY 1

#define TYPE_FLOAT 2
#define TYPE_COMPLEX 3

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
    } else 
        return -1;
    // else
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
    } else
        return -1;
    // else
}

void printVectorFloat(Vector* vector) {
    printf("vector(%.2f, %.2f, %.2f)\n", *((float*) vector->x), *((float*) vector->y), *((float*) vector->z));
}

void printVectorComplex(Vector* vector) {
    printf("vector(%.2f + (%.2f)i, %.2f + (%.2f)i, %.2f + (%.2f)i)\n", 
        ((Complex*) vector->x)->Re, ((Complex*) vector->x)->Im, 
        ((Complex*) vector->y)->Re, ((Complex*) vector->y)->Im, 
        ((Complex*) vector->z)->Re, ((Complex*) vector->z)->Im);
}

void input(int vectorType, int inputType, Vector* vector1, Vector* vector2) {
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
                float* x = (float*) malloc(sizeof(float));
                //float y = rand() % 1000 / 100.0f;
                //float z = rand() % 1000 / 100.0f;

                *x = rand() % 1000 / 100.0f;
                float y = rand() % 1000 / 100.0f;
                float z = rand() % 1000 / 100.0f;

                if (!i)
                    vector1 = makeVectorFloat(*x, y, z);
                else
                    vector2 = makeVectorFloat(*x, y, z);
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

                complex1->Re = rand() % 1000 / 100.0;
                complex1->Im = rand() % 1000 / 100.0;

                complex2->Re = rand() % 1000 / 100.0;
                complex2->Im = rand() % 1000 / 100.0;

                complex3->Re = rand() % 1000 / 100.0;
                complex3->Im = rand() % 1000 / 100.0;

                if (!i)
                    vector1 = makeVectorComplex(complex1, complex2, complex3);
                else
                    vector2 = makeVectorComplex(complex1, complex2, complex3);
            }
        }
    }
}

void printMenu() {
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
        } else if (choice == 5) {
            free(vector1);
            free(vector2);
            return;
        }
        
        vectorType = getVectorType();
        inputType = getInputType();

        srand(time(NULL));

        input(vectorType, inputType, vector1, vector2);

        switch(choice) {
            case 1:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("+\n");
                    printVectorFloat(vector2);
                    printf("=\n");
                    printVectorFloat(sumVectors(vector1, vector2));
                }

                if (vectorType == TYPE_COMPLEX) {
                    printVectorComplex(vector1);
                    printf("+\n");
                    printVectorComplex(vector2);
                    printf("=\n");
                    printVectorComplex(sumVectors(vector1, vector2));
                }
                break;
            }
            case 2:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("*\n");
                    printVectorFloat(vector2);
                    printf("=\n");

                    printf("%.2f\n", *((float*) scalarMultiply(vector1, vector2)));
                }

                if (vectorType == TYPE_COMPLEX) {
                    Complex* complex = (Complex*) scalarMultiply(vector1, vector2);

                    printVectorComplex(vector1);
                    printf("*\n");
                    printVectorComplex(vector2);
                    printf("=\n");

                    printf("%.2f + (%.2f)i\n", complex->Re, complex->Im);
                }
                break;
            }
            case 3:
            {
                if (vectorType == TYPE_FLOAT) {
                    printVectorFloat(vector1);
                    printf("x\n");
                    printVectorFloat(vector2);
                    printf("=\n");
                    printVectorFloat(vectorMultiply(vector1, vector2));
                }

                if (vectorType == TYPE_COMPLEX) {
                    printVectorComplex(vector1);
                    printf("x\n");
                    printVectorComplex(vector2);
                    printf("=\n");
                    printVectorComplex(vectorMultiply(vector1, vector2));
                }
                break;
            }
        }
    }

    free(vector1);
    free(vector2);
}