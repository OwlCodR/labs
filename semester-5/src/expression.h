#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "base_expression.h"
#include "constructions/base_construction.h"
#include "constructions/if_then_else/if_construction.h"
#include "actions/base_action.h"
#include "actions/map_action.h"

using namespace std;

#define ResultFunctionType function<vector<T>(vector<T>)>
#define IfFunctionType function<bool(vector<T>)>
#define MapFunctionType function<T(T)>

template<class T>
class Expression : public BaseExpression<T> {
public:
    Expression() {};
    Expression(vector<BaseAction<T>*> actions);
    Expression value(vector<T> values);
    IfConstruction<T> If(IfFunctionType ifFunction);
    Expression<T> Map(MapFunctionType mapFunction);
};

template<class T>
Expression<T>::Expression(vector<BaseAction<T>*> actions) {
    this->actions = actions;
}

template<class T>
Expression<T> Expression<T>::value(vector<T> values) {
    this->values = values;
    return *this;
}

template<class T>
IfConstruction<T> Expression<T>::If(IfFunctionType ifFunction) {
    return IfConstruction<T>(this, ifFunction);
}

template<class T>
Expression<T> Expression<T>::Map(MapFunctionType mapFunction) {
    this->actions.push_back(new MapAction<T>(mapFunction));
    return *this;
}

#endif