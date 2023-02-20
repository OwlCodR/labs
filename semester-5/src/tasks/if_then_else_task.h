#ifndef IF_THEN_ELSE_TASK_H
#define IF_THEN_ELSE_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../statement/then_statement.h"
#include "../log.h"

using namespace std;

#define TAG "IF_THEN_ELSE_TASK\t"

template<class T>
class IfThenElseTask : public BaseTask<T> {    
public:
    IfFunctionType ifFunction;
    ResultFunctionType thenFunction;
    ResultFunctionType elseFunction;

    IfThenElseTask(IfFunctionType ifFunction);
    vector<T> Eval(vector<T> args);
};

template<class T>
IfThenElseTask<T>::IfThenElseTask(IfFunctionType ifFunction) {
    this->ifFunction = ifFunction;
}

template<class T>
vector<T> IfThenElseTask<T>::Eval(vector<T> args) {
    Debug(TAG, ".If()" + argsToString(args));
    bool ifFunctionResult = ifFunction(args);
    vector<T> result;

    if (ifFunctionResult) {
        Debug(TAG, ".Then()");
        result = thenFunction(args);
    } else {
        Debug(TAG, ".Else()");
        result = elseFunction(args);
    }
    Debug(TAG, "Result: " + argsToString(result));
    return result;
}

#endif