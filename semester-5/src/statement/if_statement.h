#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression.h"
#include "then_statement.h"

using namespace std;

template<class T>
class IfStatement : public BaseStatement<T> {
private:
    function<bool(vector<T>)> ifFunction;
public:
    IfStatement(Expression<T>* parent, function<bool(vector<T>)> ifFunction);
    ThenStatement<T> Then(function<T(vector<T>)> thenFunction);
};

template<class T>
IfStatement<T>::IfStatement(Expression<T>* parent, function<bool(vector<T>)> ifFunction) {
    this->parent = parent;
    this->ifFunction = ifFunction;

    parent->actions.push_back(this);

    cout << "Added IfStatement to actions" << endl;
};

template<class T>
ThenStatement<T> IfStatement<T>::Then(function<T(vector<T>)> thenFunction) {
    return ThenStatement<T>(this->parent, thenFunction);
}

#endif