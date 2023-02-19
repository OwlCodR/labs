#ifndef THEN_CONSTRUCTION_H
#define THEN_CONSTRUCTION_H

#include <functional>
#include <vector>
#include "../base_construction.h"
#include "../../expression.h"
#include "if_then_else_construction.h"

using namespace std;

template<class T>
class ThenConstruction : public IfThenElseConstruction<T> {
public:
    ThenConstruction(Expression<T>* parent, IfThenElseAction<T>* action);
    Expression<T> Else(function<vector<T>(vector<T>)> function);
};

template<class T>
ThenConstruction<T>::ThenConstruction(Expression<T>* parent, IfThenElseAction<T>* action) {
    this->parent = parent;
    this->action = action;
    
    cout << "Added IfConstruction to actions" << endl;
};

template<class T>
Expression<T> ThenConstruction<T>::Else(function<vector<T>(vector<T>)> elseFunction) {
    this->action->elseFunction = elseFunction;
    this->parent->actions.push_back(this->action);
    return *(this->parent);
}

#endif