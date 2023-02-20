#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "then_statement.h"
#include "../function_types.h"
#include "../actions/if_then_else_action.h"
#include "../log.h"

using namespace std;

template<class T>
class IfStatement : public BaseStatement<T> {
private:
    IfThenElseAction<T>* action;
public:
    IfStatement(Expression<T>* parent, IfFunctionType ifFunction);
    ThenStatement<T> Then(ResultFunctionType thenFunction);
};

template<class T>
IfStatement<T>::IfStatement(Expression<T>* parent, IfFunctionType ifFunction) {
    this->parent = parent;
    this->action = new IfThenElseAction<T>(ifFunction);
};

template<class T>
ThenStatement<T> IfStatement<T>::Then(ResultFunctionType thenFunction) {
    this->action->thenFunction = thenFunction;
    return ThenStatement<T>(this->parent, this->action);
}

#endif