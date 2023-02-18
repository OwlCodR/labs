#ifndef ELSE_STATEMENT_H
#define ELSE_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"

using namespace std;

template<class T>
class ElseStatement : public BaseStatement<T> {
private:
    function<T(vector<T>)> elseFunction;
public:
    ElseStatement(Expression<T>* parent, function<T(vector<T>)> elseFunction);
    Expression<T> getResultExpression();
};

template<class T>
ElseStatement<T>::ElseStatement(Expression<T>* parent, function<T(vector<T>)> elseFunction) {
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