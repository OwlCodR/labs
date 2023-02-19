#ifndef IF_CONSTRUCTION_H
#define IF_CONSTRUCTION_H

#include <functional>
#include <vector>
#include "../base_construction.h"
#include "../../expression.h"
#include "then_construction.h"
#include "../../actions/if_then_else_action.h"
#include "if_then_else_construction.h"

using namespace std;

template<class T>
class IfConstruction : public IfThenElseConstruction<T> {
public:
    IfConstruction(Expression<T>* parent, function<bool(vector<T>)> ifFunction);
    ThenConstruction<T> Then(function<vector<T>(vector<T>)> thenFunction);
};

template<class T>
IfConstruction<T>::IfConstruction(Expression<T>* parent, function<bool(vector<T>)> ifFunction) {
    this->parent = parent;
    this->action = new IfThenElseAction<T>(ifFunction);

    cout << "Added IfConstruction to actions" << endl;
};

template<class T>
ThenConstruction<T> IfConstruction<T>::Then(function<vector<T>(vector<T>)> thenFunction) {
    this->action->thenFunction = thenFunction;
    return ThenConstruction<T>(this->parent, this->action);
}

#endif