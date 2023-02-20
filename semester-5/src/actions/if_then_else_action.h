#ifndef IF_THEN_ELSE_ACTION_H
#define IF_THEN_ELSE_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../statement/then_statement.h"

using namespace std;

template<class T>
class IfThenElseAction : public BaseAction<T> {    
public:
    IfFunctionType ifFunction;
    ResultFunctionType thenFunction;
    ResultFunctionType elseFunction;

    IfThenElseAction(IfFunctionType ifFunction);
    vector<T> Eval(vector<T> args);
};

template<class T>
IfThenElseAction<T>::IfThenElseAction(IfFunctionType ifFunction) {
    this->ifFunction = ifFunction;
}

template<class T>
vector<T> IfThenElseAction<T>::Eval(vector<T> args) {
    if (ifFunction(args)) {
        return thenFunction(args);
    } else {
        return elseFunction(args);
    }
}

#endif