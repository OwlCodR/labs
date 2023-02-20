#ifndef IF_THEN_ELSE_ACTION_H
#define IF_THEN_ELSE_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../statement/then_statement.h"
#include "../log.h"

using namespace std;

#define TAG "IF_THEN_ELSE_ACTION\t"

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
    Debug(TAG, ".If()" + argsToString(args));
    if (ifFunction(args)) {
        Debug(TAG, ".Then()");
        return thenFunction(args);
    } else {
        Debug(TAG, ".Else()");
        return elseFunction(args);
    }
}

#endif