#ifndef ELSE_STATEMENT_H
#define ELSE_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "../function_types.h"
#include "../log.h"

using namespace std;

template<class T>
class ElseStatement : public BaseStatement<T> {
private:
    ResultFunctionType elseFunction;
public:
    ElseStatement(Expression<T>* parent, ResultFunctionType elseFunction);
    Expression<T> getResultExpression();
};

template<class T>
ElseStatement<T>::ElseStatement(Expression<T>* parent, ResultFunctionType elseFunction) {
    this->parent = parent;
    this->elseFunction = elseFunction;

    this->parent->actions.push_back(this);
    
    cout << "Added ElseStatement to actions" << endl;
};

template<class T>
Expression<T> ElseStatement<T>::getResultExpression() {
    return *(this->parent);
}

#endif