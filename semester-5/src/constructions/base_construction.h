#ifndef BASE_CONSTRUCTION_H
#define BASE_CONSTRUCTION_H

#include "../expression.h"

using namespace std;

// https://ru.stackoverflow.com/questions/1013941/c-и-циклические-зависимости
template<typename T>
class Expression;

template<class T>
class BaseConstruction {
protected:
    Expression<T>* parent;
};

#endif