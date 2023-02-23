#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression/expression.h"
#include "then_statement.h"
#include "../utils/function_types.h"
#include "../tasks/if_then_else_task.h"
#include "../utils/log.h"

using namespace std;

template<class T>
class IfStatement : public BaseStatement<T> {
private:
    IfThenElseTask<T>* task;
public:
    IfStatement(Expression<T>* parent, IfFunctionType ifFunction);
    ThenStatement<T> Then(ResultFunctionType thenFunction);
};

template<class T>
IfStatement<T>::IfStatement(Expression<T>* parent, IfFunctionType ifFunction) {
    this->parent = parent;
    this->task = new IfThenElseTask<T>(ifFunction);
};

template<class T>
ThenStatement<T> IfStatement<T>::Then(ResultFunctionType thenFunction) {
    this->task->thenFunction = thenFunction;
    return ThenStatement<T>(this->parent, this->task);
}

#endif