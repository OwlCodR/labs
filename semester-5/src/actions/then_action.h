#ifndef THEN_ACTION_H
#define THEN_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "THEN_ACTION\t\t"

template<class T>
class ThenAction : public BaseAction<T> {
private:
    ResultFunctionType thenFunction;
public:
    ThenAction(ResultFunctionType thenFunction);
    vector<T> Eval(vector<T> args);
};

template<class T>
ThenAction<T>::ThenAction(ResultFunctionType thenFunction) {
    this->thenFunction = thenFunction;
}

template<class T>
vector<T> ThenAction<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Then()" + argsToString<T>(args));
    args = this->thenFunction(args);
    Debug(TAG, "Finish .Then()" + argsToString<T>(args));
    return args;
}

#endif