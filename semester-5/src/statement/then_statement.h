#ifndef THEN_STATEMENT_H
#define THEN_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "../function_types.h"
#include "../tasks/if_then_else_task.h"
#include "../log.h"

using namespace std;

template<class T>
class ThenStatement : public BaseStatement<T> {
private:
    IfThenElseTask<T>* task;
public:
    ThenStatement(Expression<T>* parent, IfThenElseTask<T>* task);
    Expression<T> Else(ResultFunctionType function);
};

template<class T>
ThenStatement<T>::ThenStatement(Expression<T>* parent, IfThenElseTask<T>* task) {
    this->parent = parent;
    this->task = task;
};

template<class T>
Expression<T> ThenStatement<T>::Else(ResultFunctionType elseFunction) {
    this->task->elseFunction = elseFunction;
    this->parent->tasks.push_back(this->task);
    return *(this->parent);
}

#endif