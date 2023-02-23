#ifndef BASE_STATEMENT_H
#define BASE_STATEMENT_H

#include "../expression/expression.h"

using namespace std;

// https://ru.stackoverflow.com/questions/1013941/c-и-циклические-зависимости
template<typename T>
class Expression;

template<class T>
class BaseStatement {
public:
    Expression<T>* parent;
};

#endif