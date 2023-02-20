#ifndef THEN_STATEMENT_H
#define THEN_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "else_statement.h"
#include "../function_types.h"
#include "../actions/if_then_else_action.h"

using namespace std;

template<class T>
class ThenStatement : public BaseStatement<T> {
private:
    IfThenElseAction<T>* action;
public:
    ThenStatement(Expression<T>* parent, IfThenElseAction<T>* action);
    Expression<T> Else(ResultFunctionType function);
};

template<class T>
ThenStatement<T>::ThenStatement(Expression<T>* parent, IfThenElseAction<T>* action) {
    this->parent = parent;
    this->action = action;
};

template<class T>
Expression<T> ThenStatement<T>::Else(ResultFunctionType elseFunction) {
    this->action->elseFunction = elseFunction;
    this->parent->actions.push_back(this->action);
    return *(this->parent);
}

#endif