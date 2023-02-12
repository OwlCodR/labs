#include "expression.h"

template<class T>
Expression<T>::Expression() {}

template<class T>
Expression<T>::Expression(vector<BaseStatement<T>*> actions) {
    this->actions = actions;
}

template<class T>
Expression<T> Expression<T>::value(vector<T> values) {
    this->values = values;
    return *this;
}

template<class T>
IfStatement<T> Expression<T>::If(IfFunctionType ifFunction) {
    IfStatement<T> statement = IfStatement<T>(this, ifFunction);
    this->actions.push_back(statement);
    return statement;
}