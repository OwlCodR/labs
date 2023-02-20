#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "base_expression.h"
#include "statement/base_statement.h"
#include "statement/if_statement.h"
#include "function_types.h"
#include "actions/map_action.h"

using namespace std;

template<class T>
class Expression : public BaseExpression<T> {
public:
    Expression();
    Expression(vector<BaseStatement<T>*> actions);
    Expression value(vector<T> values);
    IfStatement<T> If(IfFunctionType ifFunction);
    Expression<T> Map(MapFunctionType ifFunction);
};

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
    return IfStatement<T>(this, ifFunction);
}

template<class T>
Expression<T> Expression<T>::Map(MapFunctionType mapFunction) {
    this->actions.push_back(new MapAction<T>(mapFunction));
    return *this;
}

#endif