#ifndef THEN_STATEMENT_H
#define THEN_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "else_statement.h"

using namespace std;

template<class T>
class ThenStatement : public BaseStatement<T> {
private:
    function<T(vector<T>)> thenFunction;
public:
    ThenStatement(Expression<T>* parent, function<T(vector<T>)> thenFunction);
    Expression<T> Else(function<T(vector<T>)> function);
};

template<class T>
ThenStatement<T>::ThenStatement(Expression<T>* parent, function<T(vector<T>)> thenFunction) {
    this->parent = parent;
    this->thenFunction = thenFunction;
    
    this->parent->actions.push_back(this);
    
    cout << "Added IfStatement to actions" << endl;
};

template<class T>
Expression<T> ThenStatement<T>::Else(function<T(vector<T>)> elseFunction) {
    ElseStatement<T>* elseStatement = new ElseStatement<T>(this->parent, elseFunction);
    return Expression<T>(elseStatement->getResultExpression());
}

#endif